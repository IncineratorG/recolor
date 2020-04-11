#include "SetTargetColorAction.h"
#include "stores/recolor/RecolorActions.h"

SetTargetColorAction::SetTargetColorAction() {
    mPayload = nullptr;
}

int SetTargetColorAction::getType() const {
    return RecolorActions::SetTargetColor;
}

std::shared_ptr<Payload> SetTargetColorAction::getPayload() {
    return mPayload;
}

void SetTargetColorAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}

