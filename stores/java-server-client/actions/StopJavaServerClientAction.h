#ifndef STOPJAVASERVERCLIENTACTION_H
#define STOPJAVASERVERCLIENTACTION_H

#include "common/libs/redux/Action.h"

class StopJavaServerClientAction : public Action
{
public:
    StopJavaServerClientAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // STOPJAVASERVERCLIENTACTION_H
