#include "Hello.hpp"
#include <iostream>

namespace concurr {

ScopedThread::ScopedThread(std::thread&& thread)
    : thread(std::move(thread))
{
}

ScopedThread::~ScopedThread()
{
    if(thread.joinable())
    {
        std::cout << thread.get_id() << std::endl;
        thread.join();
    }
    else
    {
        thread.detach();
    }
}

// ScopedThread& ScopedThread::operator=(const ScopedThread &) = delete;
// ScopedThread::ScopedThread(const ScopedThread &) = delete;
}
