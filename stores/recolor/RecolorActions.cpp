#include "RecolorActions.h"
#include "actions/SetImagePathAction.h"
#include "actions/SetTargetColorAction.h"
#include "actions/SetTargetColorPointAction.h"
#include "actions/SetNewColorAction.h"
#include "actions/StartRecolorAction.h"

#include <QDebug>

RecolorActions::RecolorActions() {

}

std::shared_ptr<Action> RecolorActions::getAction(int type) const {
    switch (type) {
        case SetImagePath: {
            return std::make_shared<SetImagePathAction>();
        }

        case SetTargetColor: {
            return std::make_shared<SetTargetColorAction>();
        }

        case SetTargetColorPoint: {
            return std::make_shared<SetTargetColorPointAction>();
        }

        case SetNewColor: {
            return std::make_shared<SetNewColorAction>();
        }

        case StartRecolor: {
            return std::make_shared<StartRecolorAction>();
        }

        default: {
            qDebug() << __PRETTY_FUNCTION__ << "->UNKNOWN_ACTION_TYPE: " << type;
        }
    }

    return nullptr;
}
