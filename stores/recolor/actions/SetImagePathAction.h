#ifndef SETIMAGEPATHACTION_H
#define SETIMAGEPATHACTION_H

#include "common/libs/redux/Action.h"

class SetImagePathAction : public Action
{
public:
    SetImagePathAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // SETIMAGEPATHACTION_H
