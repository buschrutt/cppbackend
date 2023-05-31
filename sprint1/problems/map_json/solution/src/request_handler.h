#pragma once
#include "http_server.h"
#include "model.h"
#include <boost/json.hpp>
#include <boost/algorithm/string.hpp>

namespace http_handler {
    namespace beast = boost::beast;
    namespace http = beast::http;
    namespace json = boost::json;

    class RequestHandler {
    public:
        explicit RequestHandler(model::Game& game): game_{game} {}

        RequestHandler(const RequestHandler&) = delete;
        RequestHandler& operator=(const RequestHandler&) = delete;

        static json::array BuildAllMapsJson(const std::vector<model::Map>& maps);

        static json::object BuildMapJson(const model::Map& map);

        static json::object BuildNoMapErrorJson();

        static json::object BuildBadPathErrorJson();

        static http::response<http::string_body> BuildResponse(std::string body_str, http::status code_str);

        template <typename Body, typename Allocator, typename Send>
        void operator()(http::request<Body, http::basic_fields<Allocator>>&& req, Send&& send) {

            if (req.method() == http::verb::get) {
                std::vector<std::string> _tp;
                boost::split(_tp, req.target(), boost::is_any_of("/"));

                if (_tp.size() == 4 && _tp[1] == "api" && _tp[2] == "v1" && _tp[3] == "maps") {
                    json::array result = BuildAllMapsJson(game_.GetMaps());
                    send(std::move(BuildResponse(json::serialize(result), http::status::ok)));
                } else if (_tp.size() == 5 && _tp[1] == "api" && _tp[2] == "v1" && _tp[3] == "maps") {
                    if (game_.FindMap(model::Map::Id(_tp[4])) == nullptr) {
                        json::object result = BuildNoMapErrorJson();
                        send(std::move(BuildResponse(json::serialize(result), http::status::not_found)));
                    } else {
                        json::object result = BuildMapJson(*game_.FindMap(model::Map::Id(_tp[4])));
                        send(std::move(BuildResponse(json::serialize(result), http::status::ok)));
                    }
                } else {
                    json::object result = BuildBadPathErrorJson();
                    send(std::move(BuildResponse(json::serialize(result), http::status::bad_request)));
                }
            }
        }

    private:
        model::Game& game_;
    };

}  // namespace http_handler
