#ifndef STATE_H
#define STATE_H

#include <QMap>

#include <functional>

class State
{
public:
    virtual ~State() = 0;

    virtual int getNextSelectorId() = 0;

    std::function<void(void)> select(std::function<void(void)> selector);
    void update(std::function<void(void)> updater);

private:
    QMap<int, std::function<void(void)>> mSelectors;
};

#endif // STATE_H
