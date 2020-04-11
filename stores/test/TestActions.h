#ifndef TESTACTIONS_H
#define TESTACTIONS_H

#include "common/libs/redux/ActionsFactory.h"

class TestActions : public ActionsFactory
{
public:
    static const int Test = 1;

    TestActions();

    std::shared_ptr<Action> getAction(int type) const;
};

#endif // TESTACTIONS_H
