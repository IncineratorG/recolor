#include "Executable.h"

#include <QDebug>

Executable::Executable(std::function<void(void)> action)
    : mAction(action)
{

}

Executable::Executable(const Executable& other)
    : mAction(other.mAction)
{

}

Executable::~Executable() {
//    qDebug() << __PRETTY_FUNCTION__;
}

void Executable::execute() const {
    try {
        mAction();
    } catch (std::exception e) {

    }
}
