#include "Subscriber.h"

#include <QDebug>

Subscriber::Subscriber(std::shared_ptr<Subscription> s, std::shared_ptr<Executable> e)
    : mSubscription(s),
      mExecutable(e)
{

}

Subscriber::~Subscriber() {
//    qDebug() << __PRETTY_FUNCTION__;
}

std::shared_ptr<Subscription> Subscriber::getSubscription() {
    return mSubscription;
}

std::shared_ptr<Executable> Subscriber::getExecutable() {
    return mExecutable;
}
