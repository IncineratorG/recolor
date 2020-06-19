#ifndef JSCACTIONS_H
#define JSCACTIONS_H

#include "common/libs/redux/ActionsFactory.h"

class JSCActions : public ActionsFactory
{
public:
    static const int Test = 1;
    static const int StartJavaServerClient = 2;
    static const int StopJavaServerClient = 3;

    JSCActions();

    std::shared_ptr<Action> getAction(int type) const;
};

#endif // JSCACTIONS_H
