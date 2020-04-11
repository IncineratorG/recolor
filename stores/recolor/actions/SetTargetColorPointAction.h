#ifndef SETTARGETCOLORPOINTACTION_H
#define SETTARGETCOLORPOINTACTION_H

#include "common/libs/redux/Action.h"

class SetTargetColorPointAction : public Action
{
public:
    SetTargetColorPointAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // SETTARGETCOLORPOINTACTION_H
