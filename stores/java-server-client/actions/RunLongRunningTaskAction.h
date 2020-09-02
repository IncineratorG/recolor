#ifndef RUNLONGRUNNINGTASKACTION_H
#define RUNLONGRUNNINGTASKACTION_H

#include "common/libs/redux/Action.h"

class RunLongRunningTaskAction : public Action
{
public:
    RunLongRunningTaskAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // RUNLONGRUNNINGTASKACTION_H
