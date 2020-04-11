#include "Observable.h"

#include <QDebug>

Observable::Observable() {
    mSubscribers = std::make_shared<Subscribers>();
}

Observable::~Observable() {
//    qDebug() << __PRETTY_FUNCTION__;
}

std::shared_ptr<Subscription> Observable::subscribe(std::shared_ptr<Executable> e) {
//    std::weak_ptr<Observable> wp = weak_from_this();
//    std::shared_ptr<Observable> sp = wp.lock();

    std::shared_ptr<Observable> observablePtr = shared_from_this();

    std::shared_ptr<Subscription> subscritpion = std::make_shared<Subscription>(observablePtr);

    std::shared_ptr<Subscriber> subscriber = std::make_shared<Subscriber>(subscritpion, e);
    mSubscribers->add(subscriber);

    return subscritpion;
}

bool Observable::unsubscribe(std::shared_ptr<Subscription> s) {
    return mSubscribers->remove(s);
}

void Observable::notifySubscribers() {
    mSubscribers->runAll();
}
