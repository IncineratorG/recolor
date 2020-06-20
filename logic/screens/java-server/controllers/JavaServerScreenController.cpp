#include "JavaServerScreenController.h"
#include "stores/Stores.h"

#include <QDebug>

JavaServerScreenController::JavaServerScreenController() {
    auto stores = Stores::getInstance();

    mJSCStore = std::dynamic_pointer_cast<JSCStore>(
                stores->getStore(Stores::JavaServerClient));
}

void JavaServerScreenController::test() {
    qDebug() << __PRETTY_FUNCTION__;
}

void JavaServerScreenController::startService() {
    qDebug() << __PRETTY_FUNCTION__;

    auto startAction = mJSCStore->
            getActionsFactory()->
            getAction(JSCActions::StartJavaServerClient);
    mJSCStore->dispatch(startAction);
}

void JavaServerScreenController::stopService() {
    qDebug() << __PRETTY_FUNCTION__;

    auto stopAction = mJSCStore->
            getActionsFactory()->
            getAction(JSCActions::StopJavaServerClient);
    mJSCStore->dispatch(stopAction);
}

void JavaServerScreenController::sendData() {
    qDebug() << __PRETTY_FUNCTION__;

    auto payload = std::make_shared<Payload>("data", QString("MY_DATA"));

    auto sendDataAction = mJSCStore->
            getActionsFactory()->
            getAction(JSCActions::SendData);
    sendDataAction->setPayload(payload);

    mJSCStore->dispatch(sendDataAction);
}
