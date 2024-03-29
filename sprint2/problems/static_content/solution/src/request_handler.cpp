#include "request_handler.h"
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>

namespace http_handler {

    std::string RequestHandler::toLowerCase(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        return result;
    }

    std::string RequestHandler::urlDecode(const std::string& encodedStr) {
        std::string decodedStr;
        std::size_t length = encodedStr.length();
        std::size_t i = 0;
        while (i < length) {
            if (encodedStr[i] == '%') {
                if (i + 2 < length) {
                    std::string hex = encodedStr.substr(i + 1, 2);
                    int hexValue = std::stoi(hex, nullptr, 16);
                    decodedStr += static_cast<char>(hexValue);
                    i += 3;
                } else
                    decodedStr += encodedStr[i++];
            } else if (encodedStr[i] == '+') {
                decodedStr += ' ';
                ++i;
            } else
                decodedStr += encodedStr[i++];
        }
        return decodedStr;
    }

    bool RequestHandler::IsSubPath(fs::path path, fs::path base) {
        path = fs::weakly_canonical(path);
        base = fs::weakly_canonical(base);
        for (auto b = base.begin(), p = path.begin(); b != base.end(); ++b, ++p) {
            if (p == path.end() || *p != *b)
                return false;
        }
        return true;
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

    http::response<http::string_body> RequestHandler::BuildNotFoundError() {
        http::response<http::string_body> response;
        response.result(http::status::not_found);
        response.set(http::field::server, "Buschrutt HTTP Server");
        response.set(http::field::content_type, "text/plain");
        response.body() = "Source Not found";
        response.prepare_payload();
        return response;
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

    http::response<http::file_body> RequestHandler::BuildFileResponse(http::file_body::value_type file, http::status code_str, const std::string&  type) {
        http::response<http::file_body> response;
        response.result(code_str);
        response.set(http::field::server, "Buschrutt HTTP Server");
        response.set(http::field::content_type, type);
        response.set(http::field::transfer_encoding, "chunked");
        response.body() = std::move(file);
        response.prepare_payload();
        return response;
    }

    http::response<http::string_body> RequestHandler::BuildHeadResponse(int length, http::status code_str, const std::string& type) {
        http::response<http::string_body> response;
        response.result(code_str);
        response.set(http::field::server, "Buschrutt HTTP Server");
        response.set(http::field::content_type, type);
        response.body() = "";
        response.content_length(length);
        return response;
    }

}  // namespace http_handler
