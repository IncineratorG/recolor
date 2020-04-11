#ifndef SUBSCRIBERS_H
#define SUBSCRIBERS_H

#include "Subscriber.h"

#include <QList>

#include <memory>

class Subscribers
{
public:
    Subscribers();
    ~Subscribers();

    void add(std::shared_ptr<Subscriber> s);
    bool remove(std::shared_ptr<Subscription> s);
    void removeAll();

    void runAll();

private:
    QList<std::shared_ptr<Subscriber>> mSubscribers;
};

#endif // SUBSCRIBERS_H
