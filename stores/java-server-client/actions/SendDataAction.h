#ifndef SENDDATAACTION_H
#define SENDDATAACTION_H

#include "common/libs/redux/Action.h"

class SendDataAction : public Action
{
public:
    SendDataAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // SENDDATAACTION_H
