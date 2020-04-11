#ifndef SETTARGETCOLORACTION_H
#define SETTARGETCOLORACTION_H

#include "common/libs/redux/Action.h"

class SetTargetColorAction : public Action
{
public:
    SetTargetColorAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // SETTARGETCOLORACTION_H
