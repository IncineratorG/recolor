#include "StartJavaServerClientAction.h"
#include "stores/java-server-client/JSCActions.h"

StartJavaServerClientAction::StartJavaServerClientAction() {
    mPayload = nullptr;
}

int StartJavaServerClientAction::getType() const {
    return JSCActions::StartJavaServerClient;
}

std::shared_ptr<Payload> StartJavaServerClientAction::getPayload() {
    return mPayload;
}

void StartJavaServerClientAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
