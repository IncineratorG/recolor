#include "RunLongRunningTaskAction.h"
#include "stores/java-server-client/JSCActions.h"

RunLongRunningTaskAction::RunLongRunningTaskAction() {
    mPayload = nullptr;
}

int RunLongRunningTaskAction::getType() const {
    return JSCActions::RunLongRunningTask;
}

std::shared_ptr<Payload> RunLongRunningTaskAction::getPayload() {
    return mPayload;
}

void RunLongRunningTaskAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
