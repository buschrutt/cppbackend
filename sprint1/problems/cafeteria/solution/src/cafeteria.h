#pragma once
#ifdef _WIN32
#include <sdkddkver.h>
#endif

#include <boost/asio/io_context.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/strand.hpp>
#include <memory>
#include <chrono>
#include <boost/asio/bind_executor.hpp>
#include <utility>

#include "hotdog.h"
#include "result.h"

namespace net = boost::asio;
namespace sys = boost::system;
using namespace std::literals;
using namespace std::chrono;
using Timer = net::steady_timer;

// Function handler for hot dog preparation operation
using HotDogHandler = std::function<void(Result<HotDog> hot_dog)>;

class Order : public std::enable_shared_from_this<Order> {
public:
    Order(net::io_context& io, int id, HotDogHandler handler, Store& store, std::shared_ptr<GasCooker> gas_cooker)
            : io_{io}
            , id_{id}
            , order_gas_cooker_{std::move(gas_cooker)}
            , handler_{std::move(handler)}
            , fry_timer_{io}
            , bake_timer_{io} {
        sausage_ = store.GetSausage();
        bread_ = store.GetBread();
    }

    // Initiates the asynchronous execution of the order
    void Execute() {
        FrySausage();
        BakeBread();
    }

    void FrySausage() {
        sausage_->StartFry(*order_gas_cooker_, [shared_this = shared_from_this()]() {
            shared_this->fry_timer_.expires_after(1'500ms);  // Set the delay
            shared_this->fry_timer_.async_wait([shared_this](sys::error_code ec) {
                if (!ec) {
                    shared_this->sausage_->StopFry();
                    shared_this->CheckReadiness();
                }
            });
        });
    }

    void BakeBread() {
        bread_->StartBake(*order_gas_cooker_, [shared_this = shared_from_this()]() {
            shared_this->bake_timer_.expires_after(1'000ms);  // Set the delay
            shared_this->bake_timer_.async_wait([shared_this](sys::error_code ec) {
                if (!ec) {
                    shared_this->bread_->StopBake();
                    shared_this->CheckReadiness();
                }
            });
        });
    }

    void CheckReadiness() {
        if (sausage_->IsCooked() && bread_->IsCooked() && !is_done_) {
            is_done_ = true;
            handler_(HotDog(id_, sausage_, bread_));
        }
    }

    net::io_context& io_;
    int id_;
    std::shared_ptr<GasCooker> order_gas_cooker_;
    HotDogHandler handler_;
    Timer fry_timer_;
    Timer bake_timer_;
    net::strand<net::io_context::executor_type> strand_{net::make_strand(io_)};
    std::shared_ptr<Sausage> sausage_;
    std::shared_ptr<Bread> bread_;
    bool is_done_ = false;
};

// Cafeteria class for preparing hot dogs
class Cafeteria {
public:
    explicit Cafeteria(net::io_context& io)
            : io_{io} {
    }

    // Asynchronously prepares a hot dog and invokes the handler when the hot dog is ready.
    // This method can be called from any thread.
    void OrderHotDog(HotDogHandler handler) {
        int order_id;
        {
            std::lock_guard<std::mutex> lock(mutex_);
            order_id = ++next_order_id_;
        }
        std::make_shared<Order>(io_, order_id, std::move(handler), store_, gas_cooker_)->Execute();
    }

private:
    net::io_context& io_;
    Store store_;
    std::shared_ptr<GasCooker> gas_cooker_ = std::make_shared<GasCooker>(io_);
    int next_order_id_ = 0;
    std::mutex mutex_;
};