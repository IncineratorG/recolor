#ifndef RECOLORSTORE_H
#define RECOLORSTORE_H

#include "common/libs/redux/Store.h"
#include "RecolorState.h"
#include "RecolorActions.h"
#include "middleware/RecolorMiddlewareReduce.h"
#include "middleware/RecolorMiddlewareEffect.h"
#include "services/recolor/RecolorService.h"

class RecolorStore : public Store
{
public:
    RecolorStore();

    std::shared_ptr<State> getState() const;
    std::shared_ptr<ActionsFactory> getActionsFactory() const;

protected:
    void reduce(std::shared_ptr<Action> action);
    void effect(std::shared_ptr<Action> action);

private:
    std::shared_ptr<RecolorState> mRecolorState;
    std::shared_ptr<RecolorActions> mRecolorActions;

    RecolorMiddlewareReduce mRecolorReducer;
    RecolorMiddlewareEffect mRecolorEffect;

    std::shared_ptr<RecolorService> mRecolorService;
};

#endif // RECOLORSTORE_H
