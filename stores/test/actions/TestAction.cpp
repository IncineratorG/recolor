#include "TestAction.h"
#include "stores/test/TestActions.h"

TestAction::TestAction() {
    mPayload = nullptr;
}

int TestAction::getType() const {
    return TestActions::Test;
}

std::shared_ptr<Payload> TestAction::getPayload() {
    return mPayload;
}

void TestAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
