#include "RecolorState.h"

RecolorState::RecolorState() {
    mSelectorsIdsCounter = 0;
}

int RecolorState::getNextSelectorId() {
    return ++mSelectorsIdsCounter;
}
