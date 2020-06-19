#ifndef JSCSTATE_H
#define JSCSTATE_H

#include "common/libs/redux/State.h"

class JSCState : public State
{
public:
    JSCState();

    int getNextSelectorId();

private:
    int mSelectorsIdsCounter;
};

#endif // JSCSTATE_H
