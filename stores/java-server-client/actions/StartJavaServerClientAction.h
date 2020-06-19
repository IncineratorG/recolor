#ifndef STARTJAVASERVERCLIENTACTION_H
#define STARTJAVASERVERCLIENTACTION_H

#include "common/libs/redux/Action.h"

class StartJavaServerClientAction : public Action
{
public:
    StartJavaServerClientAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // STARTJAVASERVERCLIENTACTION_H
