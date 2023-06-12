#include "my_logger.h"

#include <string_view>
#include <thread>

using namespace std::literals;

int main() {
    // Будем устанавливать моменты времени в секундах от начала эпохи.
    // Конкретные значения не так важны, главное, что часы идут монотонно.
    Logger::GetInstance().SetTimestamp(std::chrono::system_clock::time_point{1'000'000s});

    // Логируем значения разных типов.
    LOG("Hello "sv, "world "s, 123);

    // Проверяем, что логер можно вызвать с очень большим количеством параметров.
    LOG(1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0);

    Logger::GetInstance().SetTimestamp(std::chrono::system_clock::time_point{10'000'000s});
    LOG("Brilliant logger.", " ", "I Love it");

    // Выполним ещё 100000 логирований.
    static const int attempts = 50;
    for(int i = 0; i < attempts; ++i) {
        std::chrono::system_clock::time_point ts(std::chrono::seconds(10'000'000 + i * 100));
        Logger::GetInstance().SetTimestamp(ts);

        LOG("Logging attempt ", i, ". ", "I Love it");
    }
}
