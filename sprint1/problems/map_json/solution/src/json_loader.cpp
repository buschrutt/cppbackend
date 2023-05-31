#include "json_loader.h"
#include <iostream>
#include <fstream>
#include <boost/json.hpp>

namespace json = boost::json;
using namespace std::literals;

namespace json_loader {

    model::Game LoadGame(const std::filesystem::path& json_path) {
        std::filesystem::path relative_json_path = json_path.string();
        // Загрузить содержимое файла json_path, например, в виде строки
        std::string json_str;
        std::ifstream json_i_stream(relative_json_path);
        if (json_i_stream.is_open()){
            std::stringstream buffer;
            buffer << json_i_stream.rdbuf();
            json_str = buffer.str();
        } else {
            std::cerr << "No file found" << std::endl;
        }

        // Распарсить строку как JSON, используя boost::json::parse
        auto json_value = json::parse(json_str);

        // Загрузить модель игры из файла
        model::Game game;
        auto maps = json_value.at("maps");
        for (const auto& map : maps.as_array()) {
            model::Map _map = model::Map(model::Map::Id(boost::json::value_to<std::string>(map.at("id"))),
                                         boost::json::value_to<std::string>(map.at("name")));
            auto map_roads = map.at("roads").as_array();
                for (auto road : map_roads) {
                    if (road.as_object().contains("x1"))
                        _map.AddRoad(model::Road(model::Road::HORIZONTAL,
                                                 model::Point{int(road.at("x0").as_int64()),
                                                           int(road.at("y0").as_int64())},
                                                           int(road.at("x1").as_int64())));
                    else {
                        _map.AddRoad(model::Road(model::Road::VERTICAL,
                                                 model::Point{int(road.at("x0").as_int64()),
                                                           int(road.at("y0").as_int64())},
                                                           int(road.at("y1").as_int64())));
                    }
                }
            auto map_buildings = map.at("buildings").as_array();
            for (const auto& building : map_buildings) {
                _map.AddBuilding(model::Building(model::Rectangle{model::Point{int(building.at("x").as_int64()), int(building.at("y").as_int64())},
                                                                  model::Size{int(building.at("w").as_int64()), int(building.at("h").as_int64())}}));
            }
            auto map_offices = map.at("offices").as_array();
            for (const auto& office : map_offices) {
                _map.AddOffice(model::Office(model::Office::Id(boost::json::value_to<std::string>(office.at("id"))),
                                             model::Point{int(office.at("x").as_int64()), int(office.at("y").as_int64())},
                                             model::Offset{int(office.at("offsetX").as_int64()), int(office.at("offsetY").as_int64())}));

            }
            game.AddMap(_map);
        }
        return game;
    }

}  // namespace json_loader
