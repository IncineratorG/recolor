#include "SendDataAction.h"
#include "stores/java-server-client/JSCActions.h"

SendDataAction::SendDataAction() {
    mPayload = nullptr;
}

int SendDataAction::getType() const {
    return JSCActions::SendData;
}

std::shared_ptr<Payload> SendDataAction::getPayload() {
    return mPayload;
}

void SendDataAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
