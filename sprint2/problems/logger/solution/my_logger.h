#pragma once

#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <string_view>
#include <optional>
#include <mutex>
#include <thread>
#include <iostream>

using namespace std::literals;

#define LOG(...) Logger::GetInstance().Log(__VA_ARGS__)

class Logger {
    [[nodiscard]] auto GetTime() const {
        if (manual_ts_)
            return *manual_ts_;
        return std::chrono::system_clock::now();
    }

    std::string GetTimeStamp() {
        const auto t_c = std::chrono::system_clock::to_time_t(GetTime());
        std::tm local_time{};
        localtime_s(&local_time, &t_c);
        std::stringstream ss;
        ss << std::put_time(&local_time, "%F %T");
        return ss.str();
    }

    [[nodiscard]] std::string GetFileTimeStamp() const {
        const auto t_c = std::chrono::system_clock::to_time_t(GetTime());
        std::tm local_time{};
        localtime_s(&local_time, &t_c);
        std::stringstream ss;
        ss << std::put_time(&local_time, "%Y_%m_%d");
        return ss.str();
    }

    Logger() = default;

public:
    Logger(const Logger&) = delete;

    static Logger& GetInstance() {
        static Logger obj;
        return obj;
    }

    //// <<< PRINT ARGS >>>
    template <class T>
    void PrintArgsToFile(std::ostream& os, const T& arg) {
        os << arg;
    }
    //// <<< >>>
    template <class T, class... Ts>
    void PrintArgsToFile(std::ostream& os, const T& arg, const Ts&... args) {
        os << arg;
        PrintArgsToFile(os, args...);
    }

    template<class... Ts>
    void Log(const Ts&... args) {
        std::lock_guard<std::mutex> lock(m_);
        std::ofstream log_file("/var/log/sample_log_" + GetFileTimeStamp(), std::ios_base::app); // "/var/log/sample_log_"
        log_file << GetTimeStamp() << ": ";
        PrintArgsToFile(log_file, args...);
        log_file << std::endl;
    }

    void SetTimestamp(std::chrono::system_clock::time_point ts) {
        std::lock_guard<std::mutex> lock(m_);
        manual_ts_ = ts;
    }

private:
    std::optional<std::chrono::system_clock::time_point> manual_ts_;
    std::ofstream log_file_{"sample.log"s};
    std::mutex m_;
};
