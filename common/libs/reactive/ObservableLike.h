#ifndef OBSERVABLELIKE_H
#define OBSERVABLELIKE_H

#include "Subscribers.h"
#include "Subscription.h"
#include "Executable.h"

#include <memory>

class ObservableLike
{
public:
    virtual ~ObservableLike() = 0;

    virtual std::shared_ptr<Subscription> subscribe(std::shared_ptr<Executable> e) = 0;
    virtual bool unsubscribe(std::shared_ptr<Subscription> s) = 0;

protected:
    virtual void notifySubscribers() = 0;
};

#endif // OBSERVABLELIKE_H
