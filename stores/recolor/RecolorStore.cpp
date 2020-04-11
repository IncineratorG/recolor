#include "RecolorStore.h"

#include <QDebug>

RecolorStore::RecolorStore() {
    mRecolorState = std::make_shared<RecolorState>();
    mRecolorActions = std::make_shared<RecolorActions>();
    mRecolorService = std::make_shared<RecolorService>();
}

std::shared_ptr<State> RecolorStore::getState() const {
    return mRecolorState;
}

std::shared_ptr<ActionsFactory> RecolorStore::getActionsFactory() const {
    return mRecolorActions;
}

void RecolorStore::reduce(std::shared_ptr<Action> action) {
    switch (action->getType()) {
        case RecolorActions::SetImagePath: {
            mRecolorReducer.setImagePath(mRecolorState, action);
            break;
        }

        case RecolorActions::SetTargetColor: {
            mRecolorReducer.setTargetColor(mRecolorState, action);
            break;
        }

        case RecolorActions::SetTargetColorPoint: {
            mRecolorReducer.setTargetColorPoint(mRecolorState, action);
            break;
        }

        case RecolorActions::SetNewColor: {
            mRecolorReducer.setNewColor(mRecolorState, action);
            break;
        }

//        case RecolorActions::StartRecolor: {
//            mRecolorReducer.startRecolor(mRecolorState, action);
//            break;
//        }

        default: {

        }
    }
}

void RecolorStore::effect(std::shared_ptr<Action> action) {
    switch (action->getType()) {
        case RecolorActions::StartRecolor: {
            mRecolorEffect.startRecolor(mRecolorState, action, mRecolorService);
            break;
        }

        default: {

        }
    }
}
