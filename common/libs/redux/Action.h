#ifndef ACTION_H
#define ACTION_H

#include "Payload.h"

#include <memory>

class Action
{
public:
    virtual ~Action() = 0;

    virtual int getType() const = 0;
    virtual std::shared_ptr<Payload> getPayload() = 0;
    virtual void setPayload(std::shared_ptr<Payload> p) = 0;
};

#endif // ACTION_H
