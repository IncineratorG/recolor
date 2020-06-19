#ifndef JSCMIDDLEWAREEFFECT_H
#define JSCMIDDLEWAREEFFECT_H

#include "../JSCState.h"
#include "common/libs/redux/Action.h"
#include "services/java-server-client/JavaServerClientService.h"

#include <memory>

class JSCMiddlewareEffect
{
public:
    JSCMiddlewareEffect();

    void startService(std::shared_ptr<JSCState> state,
                      std::shared_ptr<Action> action,
                      std::shared_ptr<JavaServerClientService> service);

    void stopService(std::shared_ptr<JSCState> state,
                      std::shared_ptr<Action> action,
                      std::shared_ptr<JavaServerClientService> service);
};

#endif // JSCMIDDLEWAREEFFECT_H
