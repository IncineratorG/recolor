#ifndef SETNEWCOLORACTION_H
#define SETNEWCOLORACTION_H

#include "common/libs/redux/Action.h"

class SetNewColorAction : public Action
{
public:
    SetNewColorAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // SETNEWCOLORACTION_H
