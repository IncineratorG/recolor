#include "SetImagePathAction.h"
#include "stores/recolor/RecolorActions.h"

SetImagePathAction::SetImagePathAction() {
    mPayload = nullptr;
}

int SetImagePathAction::getType() const {
    return RecolorActions::SetImagePath;
}

std::shared_ptr<Payload> SetImagePathAction::getPayload() {
    return mPayload;
}

void SetImagePathAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
