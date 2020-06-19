#include "JSCMiddlewareEffect.h"

JSCMiddlewareEffect::JSCMiddlewareEffect() {

}

void JSCMiddlewareEffect::startService(std::shared_ptr<JSCState> state,
                                       std::shared_ptr<Action> action,
                                       std::shared_ptr<JavaServerClientService> service) {
    service->start();
}

void JSCMiddlewareEffect::stopService(std::shared_ptr<JSCState> state,
                                      std::shared_ptr<Action> action,
                                      std::shared_ptr<JavaServerClientService> service) {

}
