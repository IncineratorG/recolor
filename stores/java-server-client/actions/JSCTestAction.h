#ifndef JSCTESTACTION_H
#define JSCTESTACTION_H

#include "common/libs/redux/Action.h"

class JSCTestAction : public Action
{
public:
    JSCTestAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // JSCTESTACTION_H
