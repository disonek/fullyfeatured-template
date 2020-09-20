#pragma once

#include <thread>
namespace concurr {

class ScopedThread
{
public:
    explicit ScopedThread(std::thread&& thread);
    ~ScopedThread();

    ScopedThread(const ScopedThread&) = delete;
    ScopedThread& operator=(const ScopedThread&) = delete;

private:
    std::thread thread;
};
}
