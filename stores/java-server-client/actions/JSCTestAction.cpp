#include "JSCTestAction.h"
#include "stores/java-server-client/JSCActions.h"

JSCTestAction::JSCTestAction() {
    mPayload = nullptr;
}

int JSCTestAction::getType() const {
    return JSCActions::Test;
}

std::shared_ptr<Payload> JSCTestAction::getPayload() {
    return mPayload;
}

void JSCTestAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
