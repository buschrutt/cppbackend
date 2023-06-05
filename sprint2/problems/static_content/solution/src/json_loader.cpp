#include "json_loader.h"
#include <iostream>
#include <fstream>

namespace json = boost::json;
using namespace std::literals;

namespace json_loader {

    void LoadMapRoads(const json::array& map_roads, model::Map & _map) {
        for (auto road : map_roads)
            if (road.as_object().contains("x1"))
                _map.AddRoad(model::Road(model::Road::HORIZONTAL,
                                         model::Point{int(road.at("x0").as_int64()),
                                                      int(road.at("y0").as_int64())},
                                         int(road.at("x1").as_int64())));
            else
                _map.AddRoad(model::Road(model::Road::VERTICAL,
                                         model::Point{int(road.at("x0").as_int64()),
                                                      int(road.at("y0").as_int64())},
                                         int(road.at("y1").as_int64())));
    }

    void LoadMapBuildings(const json::array& map_buildings, model::Map & _map) {
        for (const auto& building : map_buildings)
            _map.AddBuilding(model::Building(model::Rectangle{model::Point{int(building.at("x").as_int64()), int(building.at("y").as_int64())},
                                                              model::Size{int(building.at("w").as_int64()), int(building.at("h").as_int64())}}));
    }

    void LoadMapOffices(const json::array& map_offices, model::Map & _map) {
        for (const auto& office : map_offices)
            _map.AddOffice(model::Office(model::Office::Id(boost::json::value_to<std::string>(office.at("id"))),
                                         model::Point{int(office.at("x").as_int64()), int(office.at("y").as_int64())},
                                         model::Offset{int(office.at("offsetX").as_int64()), int(office.at("offsetY").as_int64())}));
    }

    //// LOAD MAPS ENTRY
    void LoadMaps(const auto & maps, model::Game & game) {
        for ([[maybe_unused]] const auto& map : maps.as_array()){
            model::Map _map = model::Map(model::Map::Id(json::value_to<std::string>(map.at("id"))),
                                         json::value_to<std::string>(map.at("name")));
            LoadMapRoads(map.at("roads").as_array(), _map);
            LoadMapBuildings(map.at("buildings").as_array(), _map);
            LoadMapOffices(map.at("offices").as_array(), _map);
            game.AddMap(_map);
        }
    }

    //// LOAD GAME ENTRY
    model::Game LoadGame(const std::filesystem::path & json_path) {
        std::filesystem::path relative_json_path = "data/" + json_path.string();
        std::string json_str;
        std::ifstream json_i_stream(relative_json_path);
        if (json_i_stream.is_open()){
            std::stringstream buffer;
            buffer << json_i_stream.rdbuf();
            json_str = buffer.str();
        } else {
            throw std::runtime_error{"--LoadGame; No file found"};
        }

        // Распарсить строку как JSON, используя boost::json::parse
        auto json_value = json::parse(json_str);

        // Загрузить модель игры из файла
        model::Game game;
        LoadMaps(json_value.at("maps"), game);
        return game;
    }

}  // namespace json_loader
