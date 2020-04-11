#ifndef TESTACTION_H
#define TESTACTION_H

#include "common/libs/redux/Action.h"

class TestAction : public Action
{
public:
    TestAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // TESTACTION_H
