#include "JSCActions.h"

#include "actions/JSCTestAction.h"
#include "actions/StartJavaServerClientAction.h"
#include "actions/StopJavaServerClientAction.h"

#include <QDebug>

JSCActions::JSCActions() {

}

std::shared_ptr<Action> JSCActions::getAction(int type) const {
    switch (type) {
        case Test: {
            return std::make_shared<JSCTestAction>();
        }

        case StartJavaServerClient: {
            return std::make_shared<StartJavaServerClientAction>();
        }

        case StopJavaServerClient: {
            return std::make_shared<StopJavaServerClientAction>();
        }

        default: {
            qDebug() << __PRETTY_FUNCTION__ << "->UNKNOWN_ACTION_TYPE: " << type;
        }
    }

    return nullptr;
}
