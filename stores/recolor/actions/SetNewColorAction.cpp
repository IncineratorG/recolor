#include "SetNewColorAction.h"
#include "stores/recolor/RecolorActions.h"

SetNewColorAction::SetNewColorAction() {
    mPayload = nullptr;
}

int SetNewColorAction::getType() const {
    return RecolorActions::SetNewColor;
}

std::shared_ptr<Payload> SetNewColorAction::getPayload() {
    return mPayload;
}

void SetNewColorAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
