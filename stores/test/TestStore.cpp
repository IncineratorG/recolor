#include "TestStore.h"

#include <QDebug>

TestStore::TestStore() {
    mTestState = std::make_shared<TestState>();
    mTestActions = std::make_shared<TestActions>();
}

std::shared_ptr<State> TestStore::getState() const {
    return mTestState;
}

std::shared_ptr<ActionsFactory> TestStore::getActionsFactory() const {
    return mTestActions;
}

void TestStore::reduce(std::shared_ptr<Action> action) {
    mTestState->update([this] () {
       mTestState->str = mTestState->str + "a";
    });

//    mTestState->str = mTestState->str + "a";

//    qDebug() << __PRETTY_FUNCTION__ << action->getType();
}

void TestStore::effect(std::shared_ptr<Action> action) {
//    qDebug() << __PRETTY_FUNCTION__ << action->getType();
}
