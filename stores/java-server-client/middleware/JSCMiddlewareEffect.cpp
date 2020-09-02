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
    service->stop();
}

void JSCMiddlewareEffect::sendData(std::shared_ptr<JSCState> state,
                                   std::shared_ptr<Action> action,
                                   std::shared_ptr<JavaServerClientService> service) {
    auto payload = action->getPayload();
    if (payload == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->PAYLOAD_IS_NULL";
        return;
    }

    try {
        auto data = std::any_cast<QString>(payload->get("data"));
        service->send(data);
    } catch (const std::bad_any_cast& e) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_ANY_CAST";
        return;
    }
}

void JSCMiddlewareEffect::runLongRunningTask(std::shared_ptr<JSCState> state,
                                   std::shared_ptr<Action> action,
                                   std::shared_ptr<JavaServerClientService> service) {
    service->runLongRunningTask();
}
