#ifdef WIN32
#include <sdkddkver.h>
#endif

#include <boost/asio.hpp>
#include <iostream>
#include "audio.h"


namespace net = boost::asio;
using net::ip::udp;
using namespace std::literals;

[[noreturn]] void StartServer(uint16_t port) {
    while(true) {
        std::cout << "listening PORT: " << port << std::endl;
        Player player(ma_format_u8, 1);
        boost::asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), port));
        std::array<char, 66000> buffer{}; //// KAK ВЫБРАТЬ?? Создаём буфер достаточного размера, чтобы вместить датаграмму.
        udp::endpoint remote_endpoint;

        auto size = socket.receive_from(boost::asio::buffer(buffer), remote_endpoint);
        auto a = std::string_view(buffer.data(), size);
        player.PlayBuffer(a.data(), size / player.GetFrameSize(), 1.5s);
        std::cout << "Playing done" << std::endl;
    }
}

void StartClient(uint16_t port, const std::string& ip_address) {
    Recorder recorder(ma_format_u8, 1);

    while(true) {
        std::string str;
        std::cout << "Press Enter to record message...";
        std::getline(std::cin, str);
        auto rec_result = recorder.Record(65000, 1.5s);
        std::cout << "Recording done" << std::endl;
        int msg_size = int(rec_result.frames) * recorder.GetFrameSize();
        try {
            net::io_context io_context;
            udp::socket socket(io_context, udp::v4());
            boost::system::error_code e;
            auto endpoint = udp::endpoint(net::ip::make_address(ip_address, e), port);
            socket.send_to(net::buffer(rec_result.data, msg_size), endpoint);
            std::cout << "Record sent to " + ip_address + ":" << port << std::endl << std::endl;
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    if (argc == 4) {
        if (std::string(argv[1]) == "client")
            StartClient(std::stoi(argv[2]), argv[3]);
    } else if (argc == 3)
        if (std::string(argv[1]) == "server") {
            StartServer(std::stoi(argv[2]));
    }
    return 0;
}
