#pragma once

#include <userver/server/handlers/http_handler_base.hpp>

class InventoryHandler : public userver::server::handlers::HttpHandlerBase {
    public:
        static constexpr std::string_view kName = "handler-inventory";

        using HttpHandlerBase::HttpHandlerBase;

        std::string HandleRequestThrow(
                const userver::server::http::HttpRequest&,
                userver::server::request::RequestContext&) const override {
            return R"({"inventory": []})";
        }
};

class InventoryWriteoffHandler : public userver::server::handlers::HttpHandlerBase {
    public:
        static constexpr std::string_view kName = "handler-inventory-writeoff";

        using HttpHandlerBase::HttpHandlerBase;

        std::string HandleRequestThrow(
                const userver::server::http::HttpRequest& request,
                userver::server::request::RequestContext&) const override {
            return R"({"status": "writeoff processed"})";
        }
};