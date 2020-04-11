#include "StartRecolorAction.h"
#include "stores/recolor/RecolorActions.h"

StartRecolorAction::StartRecolorAction() {
    mPayload = nullptr;
}

int StartRecolorAction::getType() const {
    return RecolorActions::StartRecolor;
}

std::shared_ptr<Payload> StartRecolorAction::getPayload() {
    return mPayload;
}

void StartRecolorAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
