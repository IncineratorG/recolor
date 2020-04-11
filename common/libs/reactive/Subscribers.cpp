#include "Subscribers.h"

#include <QDebug>

Subscribers::Subscribers() {

}

Subscribers::~Subscribers() {
//    qDebug() << __PRETTY_FUNCTION__;
}

void Subscribers::add(std::shared_ptr<Subscriber> s) {
    mSubscribers.append(s);
}

bool Subscribers::remove(std::shared_ptr<Subscription> s) {
    for (int i = 0; i < mSubscribers.size(); ++i) {
        if (mSubscribers.at(i)->getSubscription() == s) {
            mSubscribers.removeAt(i);
            return true;
        }
    }

    return false;
}

void Subscribers::removeAll() {
    mSubscribers.clear();
}

void Subscribers::runAll() {
    for (int i = 0; i < mSubscribers.size(); ++i) {
        if (mSubscribers.at(i)->getExecutable() != nullptr) {
            mSubscribers.at(i)->getExecutable()->execute();
        } else {
            qDebug() << __PRETTY_FUNCTION__ << "->SUBSCRIBER_AT" << i << "IS_NULL";
        }
    }
}
