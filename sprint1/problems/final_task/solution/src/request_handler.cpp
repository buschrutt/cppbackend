#include "request_handler.h"

namespace http_handler {

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

    //// %%%%%%%%%% Start Of BuildMapJson funcs %%%%%%%%%%
    json::array BuildRoadArray(const std::vector<model::Road> & roads) {
        json::array roadsArray;
        for (const auto& road : roads) {
            json::object roadObj;
            roadObj["x0"] = road.GetStart().x;
            roadObj["y0"] = road.GetStart().y;
            if (road.IsHorizontal())
                roadObj["x1"] = road.GetEnd().x;
            if (road.IsVertical())
                roadObj["y1"] = road.GetEnd().y;
            roadsArray.emplace_back(std::move(roadObj));
        }
        return roadsArray;
    }

    json::array BuildBuildingArray(const std::vector<model::Building> & buildings) {
        json::array buildingsArray;
        for (const auto& building : buildings) {
            json::object buildingObj;
            buildingObj["x"] = building.GetBounds().position.x;
            buildingObj["y"] = building.GetBounds().position.y;
            buildingObj["w"] = building.GetBounds().size.width;
            buildingObj["h"] = building.GetBounds().size.height;
            buildingsArray.emplace_back(std::move(buildingObj));
        }
        return buildingsArray;
    }

    json::array BuildOfficeArray(const std::vector<model::Office> & offices) {
        json::array officesArray;
        for (const auto& office : offices) {
            json::object officeObj;
            officeObj["id"] = office.GetId().operator*();
            officeObj["x"] = office.GetPosition().x;
            officeObj["y"] = office.GetPosition().y;
            officeObj["offsetX"] = office.GetOffset().dx;
            officeObj["offsetY"] = office.GetOffset().dy;
            officesArray.emplace_back(std::move(officeObj));
        }
        return officesArray;
    }

    json::object RequestHandler::BuildMapJson(const model::Map &map) {
        json::object result;
        result["id"] = map.GetId().operator*();
        result["name"] = map.GetName();
        result["roads"] = std::move(BuildRoadArray(map.GetRoads()));
        result["buildings"] = std::move(BuildBuildingArray(map.GetBuildings()));
        result["offices"] = std::move(BuildOfficeArray(map.GetOffices()));
        return result;
    }
    //// %%%%%%%%%% End Of BuildMapJson funcs %%%%%%%%%%

    json::object RequestHandler::BuildNoMapErrorJson() {
        json::object result;
        result["code"] = "mapNotFound";
        result["message"] = "Map not found";
        return result;
    }

    json::object RequestHandler::BuildBadPathErrorJson() {
        json::object result;
        result["code"] = "badRequest";
        result["message"] = "Bad request";
        return result;
    }

    http::response<http::string_body> RequestHandler::BuildResponse(std::string body_str, http::status status) {
        http::response<http::string_body> response;
        response.result(status);
        response.set(http::field::server, "Buschrutt HTTP Server");
        response.set(http::field::content_type, "application/json");
        response.body() = std::move(body_str);
        response.content_length(response.body().size());
        return response;
    }

}  // namespace http_handler
