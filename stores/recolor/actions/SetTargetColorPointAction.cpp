#include "SetTargetColorPointAction.h"
#include "stores/recolor/RecolorActions.h"

SetTargetColorPointAction::SetTargetColorPointAction() {
    mPayload = nullptr;
}

int SetTargetColorPointAction::getType() const {
    return RecolorActions::SetTargetColorPoint;
}

std::shared_ptr<Payload> SetTargetColorPointAction::getPayload() {
    return mPayload;
}

void SetTargetColorPointAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
