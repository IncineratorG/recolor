#include "TestScreenController.h"
#include "stores/Stores.h"
#include "stores/test/TestActions.h"

#include <QDebug>
#include <QList>

TestScreenController::TestScreenController() {
    auto stores = Stores::getInstance();

    mTestStore = std::dynamic_pointer_cast<TestStore>(
                stores->getStore(Stores::Test));
    if (mTestStore == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->TEST_STORE_IS_NULL";
        return;
    }

    auto testState = std::dynamic_pointer_cast<TestState>(
                mTestStore->getState());

    mUnsubscribe = testState->select([testState] () {
        const QString s = testState->str;

        qDebug() << "NEW_HERE: " << s;
    });
}

void TestScreenController::test() {
    qDebug() << __PRETTY_FUNCTION__;

//    const QList<int>* const list = new QList<int>();

//    for (int i = 0; i < list->length(); ++i) {
//        qDebug() << list->at(i);
//    }

//    auto testState = std::dynamic_pointer_cast<TestState>(
//                mTestStore->getState());

//    qDebug() << __PRETTY_FUNCTION__ << "->" << testState->str;
//    if (testState->str.length() > 3) {
//        qDebug() << "WILL_UNSUBSCRIBE";
//        mUnsubscribe();
//    }


    auto testAction = mTestStore->
            getActionsFactory()->
            getAction(TestActions::Test);
    mTestStore->dispatch(testAction);
}
