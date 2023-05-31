#include "request_handler.h"

namespace http_handler {

    http::response<http::string_body> RequestHandler::BuildResponse(std::string body_str) {
        http::response<http::string_body> response;
        response.result(http::status::ok);
        response.set(http::field::server, "Buschrutt HTTP Server");
        response.set(http::field::content_type, "application/json");
        response.body() = std::move(body_str);
        response.content_length(response.body().size());
        return response;
    }

    json::array RequestHandler::BuildAllMapsJson(const std::vector<model::Map>& maps) {
        json::array result;
        for (const auto& map : maps) {
            json::object mapObj;
            mapObj["id"] = map.GetId().operator*();
            mapObj["name"] = map.GetName();
            result.push_back(std::move(mapObj));
        }
        return result;
    }

    json::object RequestHandler::BuildMapJson(const model::Map &map) {
        json::object result;
        result["id"] = map.GetId().operator*();
        result["name"] = map.GetName();

        // Construct the "roads" array
        json::array roadsArray;
        for (const auto& road : map.GetRoads()) {
            json::object roadObj;
            roadObj["x0"] = road.GetStart().x;
            roadObj["y0"] = road.GetStart().y;
            if (road.IsHorizontal())
                roadObj["x1"] = road.GetEnd().x;
            if (road.IsVertical())
                roadObj["y1"] = road.GetEnd().y;
            roadsArray.emplace_back(std::move(roadObj));
        }
        result["roads"] = std::move(roadsArray);

        // Construct the "buildings" array
        json::array buildingsArray;
        for (const auto& building : map.GetBuildings()) {
            json::object buildingObj;
            buildingObj["x"] = building.GetBounds().position.x;
            buildingObj["y"] = building.GetBounds().position.y;
            buildingObj["w"] = building.GetBounds().size.width;
            buildingObj["h"] = building.GetBounds().size.height;
            buildingsArray.emplace_back(std::move(buildingObj));
        }
        result["buildings"] = std::move(buildingsArray);

        // Construct the "offices" array
        json::array officesArray;
        for (const auto& office : map.GetOffices()) {
            json::object officeObj;
            officeObj["id"] = office.GetId().operator*();
            officeObj["x"] = office.GetPosition().x;
            officeObj["y"] = office.GetPosition().y;
            officeObj["offsetX"] = office.GetOffset().dx;
            officeObj["offsetY"] = office.GetOffset().dy;
            officesArray.emplace_back(std::move(officeObj));
        }
        result["offices"] = std::move(officesArray);

        return result;
    }
}  // namespace http_handler
