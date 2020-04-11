#ifndef STORE_H
#define STORE_H

#include "Action.h"
#include "ActionsFactory.h"
#include "State.h"

class Store
{
public:
    virtual ~Store() = 0;

    void dispatch(std::shared_ptr<Action> action);

    virtual std::shared_ptr<State> getState() const = 0;
    virtual std::shared_ptr<ActionsFactory> getActionsFactory() const = 0;

protected:
    virtual void reduce(std::shared_ptr<Action> action) = 0;
    virtual void effect(std::shared_ptr<Action> action) = 0;
};

#endif // STORE_H
