#ifndef OBSERVABLEPROPERTY_H
#define OBSERVABLEPROPERTY_H

#include "ObservableLike.h"
#include "Observable.h"

#include <QDebug>

#include <memory>

template <class T> class ObservableProperty : public ObservableLike
{
public:
    ObservableProperty() {
        mObservable = std::make_shared<Observable>();
        mProperty = nullptr;
    }
    ObservableProperty(std::shared_ptr<T> value) {
        mObservable = std::make_shared<Observable>();
        mProperty = value;
    }
    ~ObservableProperty() {
//        qDebug() << __PRETTY_FUNCTION__;
    }

    void setPtr(std::shared_ptr<T> value) {
        mProperty = value;
        notifySubscribers();
    }

    std::shared_ptr<T> getPtr() const {
        return mProperty;
    }

    std::shared_ptr<Subscription> subscribe(std::shared_ptr<Executable> e) {
        if (mObservable != nullptr) {
            return mObservable->subscribe(e);
        } else {
            return nullptr;
        }
    }
    bool unsubscribe(std::shared_ptr<Subscription> s) {
        if (mObservable != nullptr) {
            return mObservable->unsubscribe(s);
        } else {
            return false;
        }
    }

protected:
    void notifySubscribers() {
        if (mObservable != nullptr) {
            mObservable->notifySubscribers();
        }
    }

private:
    std::shared_ptr<T> mProperty;
    std::shared_ptr<Observable> mObservable;
};

#endif // OBSERVABLEPROPERTY_H
