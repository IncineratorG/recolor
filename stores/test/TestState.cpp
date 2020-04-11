#include "TestState.h"

#include <QDebug>

TestState::TestState() {
    mSelectorsIdsCounter = 0;
}

int TestState::getNextSelectorId() {
    return ++mSelectorsIdsCounter;
}
