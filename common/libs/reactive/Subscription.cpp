#include "Subscription.h"
#include "Observable.h"

#include <QDebug>

Subscription::Subscription(std::shared_ptr<Observable> o) {
    mUuid = QUuid::createUuid();
    mObservable = o;
}

Subscription::~Subscription() {
//    qDebug() << __PRETTY_FUNCTION__;
}

void Subscription::unsubscribe() {
    if (mObservable.lock() != nullptr) {
        mObservable.lock()->unsubscribe(shared_from_this());
    } else {
        qDebug() << __PRETTY_FUNCTION__ << "->OBSERVABLE_IS_NULL";
    }
}

QUuid Subscription::getUuid() const {
    return mUuid;
}
