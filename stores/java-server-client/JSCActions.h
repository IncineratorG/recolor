#ifndef JSCACTIONS_H
#define JSCACTIONS_H

#include "common/libs/redux/ActionsFactory.h"

class JSCActions : public ActionsFactory
{
public:
    static const int Test = 1;
    static const int StartJavaServerClient = 2;
    static const int StopJavaServerClient = 3;
    static const int SendData = 4;
    static const int RunLongRunningTask = 5;

    JSCActions();

    std::shared_ptr<Action> getAction(int type) const;
};

#endif // JSCACTIONS_H
