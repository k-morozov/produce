//
// Created by focus on 28.10.2021.
//

#include <iostream>
#include <thread>

#include "Consumer.h"


Consumer::Consumer(MiddlewarePtr mid) :
    mid_(std::move(mid))
{

}

void Consumer::run()
{
    std::thread::id id = std::this_thread::get_id();
    size_t taskCounter = 0;
    while (!mid_->isFinished())
    {
        std::unique_lock lck(mid_->getM());
        mid_->getGoConsume().wait(lck,
                                  [&]{ return !mid_->emptyTasks() || mid_->isFinished(); });
        if (!mid_->emptyTasks())
        {
            auto task = mid_->popTask();
//            std::lock_guard l(displayMutex_);
            std::cout << "thread:" << id << ", task: " << task << std::endl;
            taskCounter++;
        }

    }
    std::lock_guard l(displayMutex_);
    std::cout << "thread:" << id << " is done, counter = " << taskCounter << std::endl;
}
