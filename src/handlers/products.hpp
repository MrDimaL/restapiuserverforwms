#pragma once

#include <userver/server/handlers/http_handler_base.hpp>

class ProductsHandler : public userver::server::handlers::HttpHandlerBase {
    public:
        static constexpr std::string_view kName = "handler-products";

        using HttpHandlerBase::HttpHandlerBase;

        std::string HandleRequestThrow(
                const userver::server::http::HttpRequest&,
                userver::server::request::RequestContext&) const override {
            return R"({"products": []})";
        }
};


class ProductsCreateHandler : public userver::server::handlers::HttpHandlerBase {
    public:
        static constexpr std::string_view kName = "handler-products-create";

        using HttpHandlerBase::HttpHandlerBase;

        std::string HandleRequestThrow(
                const userver::server::http::HttpRequest& request,
                userver::server::request::RequestContext&) const override {
            return R"({"id": 1, "status": "created"})";
        }
};

class ProductsUpdateHandler : public userver::server::handlers::HttpHandlerBase {
    public:
        static constexpr std::string_view kName = "handler-products-update";

        using HttpHandlerBase::HttpHandlerBase;

        std::string HandleRequestThrow(
                const userver::server::http::HttpRequest& request,
                userver::server::request::RequestContext&) const override {
            auto id = request.GetPathArg("id");
            return R"({"id": )" + id + R"(, "status": "updated"})";
        }
};

class ProductsDeleteHandler : public userver::server::handlers::HttpHandlerBase {
    public:
        static constexpr std::string_view kName = "handler-products-delete";

        using HttpHandlerBase::HttpHandlerBase;

        std::string HandleRequestThrow(
                const userver::server::http::HttpRequest& request,
                userver::server::request::RequestContext&) const override {
            auto id = request.GetPathArg("id");
            return R"({"id": )" + id + R"(, "status": "deleted"})";
        }
};

class ProductsSearchHandler : public userver::server::handlers::HttpHandlerBase {
public:
    static constexpr std::string_view kName = "handler-products-search";

    using HttpHandlerBase::HttpHandlerBase;

    std::string HandleRequestThrow(
            const userver::server::http::HttpRequest& request,
            userver::server::request::RequestContext&) const override {
        auto query = request.GetArg("q");
        if (query.empty()) {
            query = "none";
        } else {
            return R"([{"id": 1, "name": "Search result for ")" + query + R"("}])";
        }
    }
};