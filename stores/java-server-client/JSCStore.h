#ifndef JSCSTORE_H
#define JSCSTORE_H

#include "common/libs/redux/Store.h"
#include "JSCState.h"
#include "JSCActions.h"
#include "services/java-server-client/JavaServerClientService.h"
#include "middleware/JSCMiddlewareEffect.h"

class JSCStore : public Store
{
public:
    JSCStore();

    std::shared_ptr<State> getState() const;
    std::shared_ptr<ActionsFactory> getActionsFactory() const;

protected:
    void reduce(std::shared_ptr<Action> action);
    void effect(std::shared_ptr<Action> action);

private:
    std::shared_ptr<JSCState> mJSCState;
    std::shared_ptr<JSCActions> mJSCActions;

    JSCMiddlewareEffect mJSCEffect;

    std::shared_ptr<JavaServerClientService> mJavaServerClientService;
};

#endif // JSCSTORE_H
