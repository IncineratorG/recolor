#include "TestActions.h"

#include "actions/TestAction.h"

#include <QDebug>

TestActions::TestActions() {

}

std::shared_ptr<Action> TestActions::getAction(int type) const {
    switch (type) {
        case Test: {
            return std::make_shared<TestAction>();
        }

        default: {
            qDebug() << __PRETTY_FUNCTION__ << "->UNKNOWN_ACTION_TYPE: " << type;
        }
    }

    return nullptr;
}
