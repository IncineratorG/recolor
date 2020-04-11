#ifndef STARTRECOLORACTION_H
#define STARTRECOLORACTION_H

#include "common/libs/redux/Action.h"

class StartRecolorAction : public Action
{
public:
    StartRecolorAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // STARTRECOLORACTION_H
