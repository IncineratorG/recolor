#ifndef RECOLORACTIONS_H
#define RECOLORACTIONS_H

#include "common/libs/redux/ActionsFactory.h"

class RecolorActions : public ActionsFactory
{
public:
    static const int SetImagePath = 1;
    static const int SetTargetColor = 2;
    static const int SetNewColor = 3;
    static const int SetTargetColorPoint = 4;
    static const int StartRecolor = 5;

    RecolorActions();

    std::shared_ptr<Action> getAction(int type) const;
};

#endif // RECOLORACTIONS_H
