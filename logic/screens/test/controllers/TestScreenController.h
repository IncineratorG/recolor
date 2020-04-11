#ifndef TESTSCREENCONTROLLER_H
#define TESTSCREENCONTROLLER_H

#include "stores/test/TestStore.h"

#include <QObject>

class TestScreenController : public QObject
{
    Q_OBJECT

public:
    TestScreenController();

    Q_INVOKABLE void test();

private:
    std::shared_ptr<TestStore> mTestStore;
    std::function<void(void)> mUnsubscribe;
};

#endif // TESTSCREENCONTROLLER_H
