#include "sdk.h"
#include "json_loader.h"
#include "request_handler.h"

#include <boost/asio/io_context.hpp>
#include <boost/json.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
#include <mutex>
#include <vector>
#include <thread>

using namespace std::literals;
namespace net = boost::asio;
namespace sys = boost::system;
namespace json = boost::json;

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

//BOOST_LOG_ATTRIBUTE_KEYWORD(additional_data, "AdditionalData", json::value)

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[]) {
/*
    if (argc < 2) {
        std::cerr << "Usage: game_server <game-config-json>"sv << std::endl;
        return EXIT_FAILURE;
    }
*/
    BOOST_LOG_TRIVIAL(info) << "INFO FLAG 00!!"sv;
    std::string argv_1 = "data/config.json";
    std::string argv_2 = "static";
    try {
        // 1. Загружаем карту из файла и построить модель игры
        model::Game game = json_loader::LoadGame(argv_1/*argv[1]*/);

        // 2. Инициализируем io_context
        const unsigned num_threads = std::thread::hardware_concurrency();
        net::io_context ioc((int)num_threads);

        // 3. Добавляем асинхронный обработчик сигналов SIGINT и SIGTERM
        net::signal_set signals(ioc, SIGINT, SIGTERM);
        signals.async_wait([&ioc](const sys::error_code& ec, [[maybe_unused]] int signal_number) {
            if (!ec) {
                std::cout << "Signal "sv << signal_number << " received"sv << std::endl;
                ioc.stop();
            }
        });

        // 4. Создаём обработчик HTTP-запросов и связываем его с моделью игры
        http_handler::RequestHandler handler{game};

        // 5. Запустить обработчик HTTP-запросов, делегируя их обработчику запросов
        const auto address = net::ip::make_address("0.0.0.0");
        constexpr net::ip::port_type port = 8080;
        http_server::ServerHttp(ioc, {address, port}, [&handler, arg2 = argv_2/*argv[2]*/](auto&& req, auto&& send) {
            handler(std::forward<decltype(req)>(req), std::forward<decltype(send)>(send), arg2);
        });

        // Эта надпись сообщает тестам о том, что сервер запущен и готов обрабатывать запросы
        std::cout << "FLAG--Server has started..."sv << std::endl;
        //json::value custom_data{{"code"s, 0}};

        // 6. Запускаем обработку асинхронных операций
        RunThreads(std::max(1u, num_threads), [&ioc] {
            ioc.run();
        });
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
}
