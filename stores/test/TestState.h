#ifndef TESTSTATE_H
#define TESTSTATE_H

#include "common/libs/redux/State.h"

#include <QString>
#include <QList>
#include <QMap>

class TestState : public State
{
public:
    QString str;

    TestState();

    int getNextSelectorId();

private:
    int mSelectorsIdsCounter;
};

#endif // TESTSTATE_H
