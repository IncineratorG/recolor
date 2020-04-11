#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include <functional>

class Executable
{
public:
    Executable(std::function<void(void)> action);
    Executable(const Executable& other);
    ~Executable();

    void execute() const;

private:
    std::function<void(void)> mAction;
};

#endif // EXECUTABLE_H
