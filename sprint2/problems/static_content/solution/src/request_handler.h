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
        explicit RequestHandler(model::Game& game): game_{game} {
            contentTypeMap_ = { {"htm", "text/html"}, {"html", "text/html"}, {"css", "text/css"},
                                {"txt", "text/plain"}, {"js", "text/javascript"}, {"json", "application/json"},
                                {"xml", "application/xml"}, {"png", "image/png"}, {"jpg", "image/jpeg"},
                                {"jpe", "image/jpeg"}, {"jpeg", "image/jpeg"}, {"gif", "image/gif"},
                                {"bmp", "image/bmp"}, {"ico", "image/vnd.microsoft.icon"}, {"tiff", "image/tiff"},
                                {"tif", "image/tiff"}, {"svg", "image/svg+xml"}, {"svgz", "image/svg+xml"},
                                {"mp3", "audio/mpeg"}
            };
        }

        RequestHandler(const RequestHandler&) = delete;
        RequestHandler& operator=(const RequestHandler&) = delete;

        static std::string toLowerCase(const std::string& str);

        static std::string urlDecode(const std::string& encodedStr);

        static json::array BuildAllMapsJson(const std::vector<model::Map>& maps);

        static json::object BuildMapJson(const model::Map& map);

        static json::object BuildNoMapErrorJson();

        static json::object BuildBadPathErrorJson();

        static http::response<http::string_body> BuildResponse(std::string body_str, http::status status);

        static http::response<http::string_body> BuildSourceResponse(std::string body_str,
                                                                     http::status status,
                                                                     std::string type);

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
                } else if (!_tp.empty() && _tp[1] == "api") {
                    json::object result = BuildBadPathErrorJson();
                    send(std::move(BuildResponse(json::serialize(result), http::status::bad_request)));
                } else {
                    std::string str_request = urlDecode(req.target().to_string());
                    std::string source_name = urlDecode(_tp[_tp.size() - 1]);
                    std::size_t lastDotIndex = source_name.find_last_of('.');
                    std::string source_type;
                    if (lastDotIndex != std::string::npos) {
                        source_type = toLowerCase(source_name.substr(lastDotIndex + 1));
                    } else {
                        source_type = "";
                    }
                    std::string resource_path = "static/" + str_request;
                    http::file_body::value_type file;

                    if (boost::system::error_code ec; file.open(resource_path.c_str(), beast::file_mode::read, ec), ec) {
                        throw std::runtime_error{"--Failed to open file --" + resource_path};
                    }
                    std::string type;
                    if (contentTypeMap_.contains(source_type))
                        type = contentTypeMap_.at(source_type);
                    else
                        type = "application/octet-stream";
                    http::response<http::file_body> response;
                    response.result(http::status::ok);
                    response.set(http::field::server, "Buschrutt HTTP Server");
                    response.set(http::field::content_type, type);
                    response.set(http::field::transfer_encoding, "chunked");
                    response.body() = std::move(file);
                    response.prepare_payload();
                    send(std::move(response));
                }
            }
        }

    private:
        model::Game& game_;
        std::map<std::string, std::string>  contentTypeMap_;
    };

}  // namespace http_handler
