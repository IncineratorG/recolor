#include "State.h"

#include <QDebug>

State::~State() {

}

std::function<void(void)> State::select(std::function<void(void)> selector) {
    try {
        selector();
    } catch (std::exception e) {
        qDebug() << __PRETTY_FUNCTION__ << "->EXCEPTION";
        return nullptr;
    }

    const int selectorId = getNextSelectorId();

    mSelectors.insert(selectorId, selector);

    std::function<void(void)> unsubscribe = [this, selectorId] () {
      mSelectors.remove(selectorId);
    };

    return unsubscribe;
}

void State::update(std::function<void ()> updater) {
    try {
        updater();
    } catch (std::exception e) {
        qDebug() << __PRETTY_FUNCTION__ << "->EXCEPTION";
        return;
    }

    QList<std::function<void(void)>> values = mSelectors.values();
    for (int i = 0; i < values.length(); ++i) {
        try {
            values.at(i)();
        } catch (std::exception e) {
            qDebug() << __PRETTY_FUNCTION__ << "->EXCEPTION_EE";
        }
    }
}

