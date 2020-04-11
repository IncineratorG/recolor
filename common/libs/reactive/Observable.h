#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "ObservableLike.h"

#include <memory>

class Observable : public std::enable_shared_from_this<Observable>, public ObservableLike
{
public:
    Observable();
    ~Observable();

    std::shared_ptr<Subscription> subscribe(std::shared_ptr<Executable> e);
    bool unsubscribe(std::shared_ptr<Subscription> s);

    void notifySubscribers();

private:
    std::shared_ptr<Subscribers> mSubscribers;
};

#endif // OBSERVABLE_H
