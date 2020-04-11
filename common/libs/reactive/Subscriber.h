#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Subscription.h"
#include "Executable.h"

#include <memory>

class Subscriber
{
public:
    Subscriber(std::shared_ptr<Subscription> s, std::shared_ptr<Executable> e);
    ~Subscriber();

    std::shared_ptr<Subscription> getSubscription();
    std::shared_ptr<Executable> getExecutable();

private:
    std::shared_ptr<Subscription> mSubscription;
    std::shared_ptr<Executable> mExecutable;
};

#endif // SUBSCRIBER_H
