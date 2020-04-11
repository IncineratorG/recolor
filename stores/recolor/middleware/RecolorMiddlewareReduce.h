#ifndef RECOLORMIDDLEWAREREDUCE_H
#define RECOLORMIDDLEWAREREDUCE_H

#include "../RecolorState.h"
#include "common/libs/redux/Action.h"

#include <memory>

class RecolorMiddlewareReduce
{
public:
    RecolorMiddlewareReduce();

    void setImagePath(std::shared_ptr<RecolorState> state,
                      std::shared_ptr<Action> action);
    void setTargetColor(std::shared_ptr<RecolorState> state,
                        std::shared_ptr<Action> action);
    void setTargetColorPoint(std::shared_ptr<RecolorState> state,
                             std::shared_ptr<Action> action);
    void setNewColor(std::shared_ptr<RecolorState> state,
                        std::shared_ptr<Action> action);
//    void startRecolor(std::shared_ptr<RecolorState> state,
//                      std::shared_ptr<Action> action);
};

#endif // RECOLORMIDDLEWAREREDUCE_H
