#include "JSCStore.h"

#include <QDebug>

JSCStore::JSCStore() {
    mJSCState = std::make_shared<JSCState>();
    mJSCActions = std::make_shared<JSCActions>();
    mJavaServerClientService = std::make_shared<JavaServerClientService>();
}

std::shared_ptr<State> JSCStore::getState() const {
    return mJSCState;
}

std::shared_ptr<ActionsFactory> JSCStore::getActionsFactory() const {
    return mJSCActions;
}

void JSCStore::reduce(std::shared_ptr<Action> action) {

}

void JSCStore::effect(std::shared_ptr<Action> action) {
    switch (action->getType()) {
        case JSCActions::StartJavaServerClient: {
            mJSCEffect.startService(mJSCState, action, mJavaServerClientService);
            break;
        }

        case JSCActions::StopJavaServerClient: {
            mJSCEffect.stopService(mJSCState, action, mJavaServerClientService);
            break;
        }

        case JSCActions::SendData: {
            mJSCEffect.sendData(mJSCState, action, mJavaServerClientService);
            break;
        }

        default: {

        }
    }
}
