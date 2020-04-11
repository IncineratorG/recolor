#ifndef RECOLORSTATE_H
#define RECOLORSTATE_H

#include "common/libs/redux/State.h"

#include <QString>
#include <QColor>
#include <QPoint>

class RecolorState : public State
{
public:
    QString imagePath;
    QColor targetColor;
    QPoint targetPoint;
    QColor newColor;
    bool recoloring = false;

    // ===
    QColor testColor;
    // ===

    RecolorState();

    int getNextSelectorId();

private:
    int mSelectorsIdsCounter;
};

#endif // RECOLORSTATE_H
