#pragma once

#include <userver/server/handlers/http_handler_base.hpp>

class UserHandler : public userver::server::handlers::HttpHandlerBase {
    public:
        static constexpr std::string_view kName = "handler-user";

        using HttpHandlerBase::HttpHandlerBase;

        std::string HandleRequestThrow(
                const userver::server::http::HttpRequest& request,
                userver::server::request::RequestContext&) const override {
            auto username = request.GetPathArg("username");
            return R"({"username": ")" + username + R"(", "name": "Демо"})";
        }
};