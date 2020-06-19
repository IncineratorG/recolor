#include "JSCState.h"

JSCState::JSCState() {
    mSelectorsIdsCounter = 0;
}

int JSCState::getNextSelectorId() {
    return ++mSelectorsIdsCounter;
}
