//#include "sdk.h"
#include "json_loader.h"
#include "request_handler.h"

#include <boost/log/trivial.hpp>     // для BOOST_LOG_TRIVIAL
#include <boost/log/core.hpp>        // для logging::core
#include <boost/log/expressions.hpp> // для выражения, задающего фильтр
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/date_time.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/json.hpp>
#include <boost/asio/signal_set.hpp>
#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
#include <string_view>

using namespace std::literals;

namespace net = boost::asio;
namespace sys = boost::system;
namespace json = boost::json;
namespace sinks = boost::log::sinks;
namespace logging = boost::log;
namespace keywords = boost::log::keywords;
namespace sinks = boost::log::sinks;

BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "LineID", unsigned int)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "TimeStamp", boost::posix_time::ptime)

BOOST_LOG_ATTRIBUTE_KEYWORD(file, "File", std::string)
BOOST_LOG_ATTRIBUTE_KEYWORD(line, "Line", int)

BOOST_LOG_ATTRIBUTE_KEYWORD(additional_data, "AdditionalData", json::value)

void MyFormatter(logging::record_view const& rec, logging::formatting_ostream& strm) {
    strm << "{";
    // timestamp
    auto ts = *rec[timestamp];
    strm << "\"timestamp\":\"" << to_iso_extended_string(ts) << "\"";
    strm << ",";
    // data
    auto data = rec[additional_data].get_ptr<json::value>();
    if (data->if_object())
        strm << "\"data\":" << data->as_object();
    else
        strm << "\"data\":\"\"";
    // message
    strm << ",";
    strm << "\"message\":\"" << rec[logging::expressions::smessage] << "\"";
    strm << "}" << std::endl;
}

namespace {

    // Запускает функцию fn на n потоках, включая текущий
    template <typename Fn>
    void RunThreads(unsigned n, const Fn& fn) {
        n = std::max(1u, n);
        std::vector<std::jthread> workers;
        workers.reserve(n - 1);
        // Запускаем n-1 рабочих потоков, выполняющих функцию fn
        while (--n) {
            workers.emplace_back(fn);
        }
        fn();
    }

}  // namespace

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[]) {

    logging::add_common_attributes();
    logging::add_console_log(std::cout, keywords::format = &MyFormatter, keywords::auto_flush = true);

    if (argc < 2) {
        std::cerr << "Usage: game_server <game-config-json>"sv << std::endl;
        return EXIT_FAILURE;
    }

    /*
    std::string argv_1 = "data/config.json";
    std::string argv_2 = "static";
     */
    try {
        // 1. Загружаем карту из файла и построить модель игры
        model::Game game = json_loader::LoadGame(/*argv_1*/argv[1]);

        // 2. Инициализируем io_context
        const unsigned num_threads = std::thread::hardware_concurrency();
        net::io_context ioc((int)num_threads);

        // 3. Добавляем асинхронный обработчик сигналов SIGINT и SIGTERM
        net::signal_set signals(ioc, SIGINT, SIGTERM);
        signals.async_wait([&ioc](const sys::error_code& ec, [[maybe_unused]] int signal_number) {
            if (!ec) {
                json::value custom_data{{"code", 0}};
                BOOST_LOG_TRIVIAL(info) << logging::add_value(additional_data, custom_data) << "server exited"sv;
                ioc.stop();
            }
        });

        // 4. Создаём обработчик HTTP-запросов и связываем его с моделью игры
        http_handler::RequestHandler handler{game};

        // 5. Запустить обработчик HTTP-запросов, делегируя их обработчику запросов
        const auto address = net::ip::make_address("0.0.0.0");
        constexpr net::ip::port_type port = 8080;
        http_server::ServerHttp(ioc, {address, port}, [&handler, arg2 = argv[2]/*argv_2*/](auto&& req, auto&& send) {
            handler(std::forward<decltype(req)>(req), std::forward<decltype(send)>(send), arg2);
        });

        // Server started massage
        json::value custom_data{{"port", port}, {"address", address.to_string()}};
        BOOST_LOG_TRIVIAL(info) << logging::add_value(additional_data, custom_data) << "server started"sv;

        // 6. Запускаем обработку асинхронных операций
        RunThreads(std::max(1u, num_threads), [&ioc] {
            ioc.run();
        });
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
}
