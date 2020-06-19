#include "StopJavaServerClientAction.h"
#include "stores/java-server-client/JSCActions.h"

StopJavaServerClientAction::StopJavaServerClientAction() {
    mPayload = nullptr;
}

int StopJavaServerClientAction::getType() const {
    return JSCActions::Test;
}

std::shared_ptr<Payload> StopJavaServerClientAction::getPayload() {
    return mPayload;
}

void StopJavaServerClientAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
