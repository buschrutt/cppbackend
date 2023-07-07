#pragma once
#include "http_server.h"
#include "model.h"
#include <boost/json.hpp>
#include <boost/algorithm/string.hpp>
#include <filesystem>
#include <boost/beast/http.hpp>

namespace http_handler {

    namespace beast = boost::beast;
    namespace http = beast::http;
    namespace json = boost::json;
    namespace fs = std::filesystem;

    template<class RequestHandler>
    class RequestHandlerWithLog {
    public:
        template <typename Body, typename Allocator, typename Send>
        void operator()(http::request<Body, http::basic_fields<Allocator>>&& req, Send&& send, const std::string& content_adr) {
            LogRequest(req);
            //auto Response resp = decorated_(std::move(req));
            //LogResponse(resp);
            //return resp;
        }

    private:
        static void LogRequest(const auto& r) {
            std::cout << "FLAG00" <<std::endl;
        };
        static void LogResponse(const auto& r) {
            std::cout << "FLAG01" <<std::endl;
        };
        RequestHandler& decorated_;
    };

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

        static bool IsSubPath(fs::path path, fs::path base);

        static json::array BuildAllMapsJson(const std::vector<model::Map>& maps);

        static json::object BuildMapJson(const model::Map& map);

        static json::object BuildNoMapErrorJson();

        static json::object BuildBadPathErrorJson();

        static http::response<http::string_body> BuildNotFoundError();

        static http::response<http::string_body> BuildResponse(std::string body_str, http::status code_str);

        static http::response<http::file_body> BuildFileResponse(http::file_body::value_type file, http::status code_str, const std::string&  type);

        static http::response<http::string_body> BuildHeadResponse(int length, http::status code_str, const std::string& type);

        template <typename Body, typename Allocator, typename Send>
        void operator()(http::request<Body, http::basic_fields<Allocator>>&& req, Send&& send, const std::string& content_adr) {
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
                    //// GET source if-else case:
                    std::string str_request = urlDecode(req.target().to_string());
                    if (_tp[_tp.size() - 1].empty()) str_request = str_request + "index.html";
                    std::string source_type = (!str_request.empty() && str_request.find_last_of('.') != std::string::npos)?
                            toLowerCase(str_request.substr(str_request.find_last_of('.') + 1)): "";
                    std::string resource_path = content_adr + str_request;
                    if (!IsSubPath(resource_path, content_adr)) {
                        json::object result = BuildBadPathErrorJson();
                        send(std::move(BuildResponse(json::serialize(result), http::status::bad_request)));
                        return;
                    }
                    http::file_body::value_type file;
                    std::string type = (contentTypeMap_.contains(source_type))?
                            contentTypeMap_.at(source_type): "application/octet-stream";
                    if (boost::system::error_code ec; file.open(resource_path.c_str(), beast::file_mode::read, ec), ec) {
                        send(std::move(BuildNotFoundError()));
                        return;
                    }
                    http::response<http::file_body> response = BuildFileResponse(std::move(file), http::status::ok, type);
                    send(std::move(response));
                }
            } else if (req.method() == http::verb::head) {
                std::vector<std::string> _tp;
                boost::split(_tp, req.target(), boost::is_any_of("/"));
                if (!_tp.empty() && _tp[1] != "api") {
                    //// HEAD source if-else case:
                    std::string str_request = urlDecode(req.target().to_string());
                    if (_tp[_tp.size() - 1].empty()) str_request = str_request + "index.html";
                    std::string source_type = (!str_request.empty() && str_request.find_last_of('.') != std::string::npos)?
                                              toLowerCase(str_request.substr(str_request.find_last_of('.') + 1)): "";
                    std::string resource_path = content_adr + str_request;
                    if (!IsSubPath(resource_path, content_adr)) {
                        json::object result = BuildBadPathErrorJson();
                        send(std::move(BuildResponse(json::serialize(result), http::status::bad_request)));
                        return;
                    }
                    http::file_body::value_type file;
                    std::string type = (contentTypeMap_.contains(source_type))?
                                       contentTypeMap_.at(source_type): "application/octet-stream";
                    if (boost::system::error_code ec; file.open(resource_path.c_str(), beast::file_mode::read, ec), ec) {
                        send(std::move(BuildNotFoundError()));
                        return;
                    }
                    http::response<http::string_body> response = BuildHeadResponse(int(file.size()), http::status::ok, type);
                    send(std::move(response));
                }
            }
        }

    private:
        model::Game& game_;
        std::map<std::string, std::string>  contentTypeMap_;
    };

}  // namespace http_handler
