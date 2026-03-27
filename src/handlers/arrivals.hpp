#pragma once

#include <userver/server/handlers/http_handler_base.hpp>

// GET /arivals
class ArrivalsHandlerGet : public userver::server::handlers::HttpHandlerBase {
public:
    static constexpr std::string_view kName = "handler-arrivals-get";

    using HttpHandlerBase::HttpHandlerBase;

    std::string HandleRequestThrow(
        const userver::server::http::HttpRequest&,
        userver::server::request::RequestContext&) const override {
        return R"([{"id": 1, "product": "Товар", "quantity": 100, "date": "2026-03-27"}])";
    }
};

// POST /arivals
class ArrivalsHandlerPost : public userver::server::handlers::HttpHandlerBase {
public:
    static constexpr std::string_view kName = "handler-arrivals-post";

    using HttpHandlerBase::HttpHandlerBase;

    std::string HandleRequestThrow(
        const userver::server::http::HttpRequest& request,
        userver::server::request::RequestContext&) const override {
        return R"({"status": "created"})";
    }
};