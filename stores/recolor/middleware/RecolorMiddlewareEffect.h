#ifndef RECOLORMIDDLEWAREEFFECT_H
#define RECOLORMIDDLEWAREEFFECT_H

#include "../RecolorState.h"
#include "common/libs/redux/Action.h"
#include "services/recolor/RecolorService.h"

#include <memory>

class RecolorMiddlewareEffect
{
public:
    RecolorMiddlewareEffect();

    void startRecolor(std::shared_ptr<RecolorState> state,
                      std::shared_ptr<Action> action,
                      std::shared_ptr<RecolorService> service);
};

#endif // RECOLORMIDDLEWAREEFFECT_H
