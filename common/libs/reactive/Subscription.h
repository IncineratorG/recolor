#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

#include "Executable.h"

#include <QString>
#include <QUuid>

#include <memory>

class Observable;
class Subscription : public std::enable_shared_from_this<Subscription>
{
public:
    Subscription(std::shared_ptr<Observable> o);
    ~Subscription();

    void unsubscribe();

    QUuid getUuid() const;

    bool operator==(const Subscription& other) const {
        return this->mUuid == other.mUuid;
    }

private:
    QUuid mUuid;
    std::weak_ptr<Observable> mObservable;
};

inline uint qHash(const Subscription& s) {
    return qHash(s.getUuid());
}

#endif // SUBSCRIPTION_H
