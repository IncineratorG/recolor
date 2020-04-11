#ifndef ACTIONSFACTORY_H
#define ACTIONSFACTORY_H

#include "Action.h"

class ActionsFactory
{
public:
    virtual ~ActionsFactory() = 0;

    virtual std::shared_ptr<Action> getAction(int type) const = 0;
};

#endif // ACTIONSFACTORY_H
