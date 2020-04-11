#ifndef TESTSTORE_H
#define TESTSTORE_H

#include "common/libs/redux/Store.h"
#include "TestState.h"
#include "TestActions.h"

class TestStore : public Store
{
public:
    TestStore();

    std::shared_ptr<State> getState() const;
    std::shared_ptr<ActionsFactory> getActionsFactory() const;

protected:
    void reduce(std::shared_ptr<Action> action);
    void effect(std::shared_ptr<Action> action);

private:
    std::shared_ptr<TestState> mTestState;
    std::shared_ptr<TestActions> mTestActions;
};

#endif // TESTSTORE_H
