//
// Created by focus on 28.10.2021.
//

#include <iostream>

#include "Consumer.h"


Consumer::Consumer(MiddlewarePtr mid) :
    mid_(std::move(mid))
{

}

void Consumer::run()
{
    while (!mid_->isFinished())
    {
        std::unique_lock lck(mid_->getM());
        mid_->getGoConsume().wait(lck,
                                  [&]{return !mid_->emptyTasks(); });
        auto task = mid_->popTask();
        std::cout << "Task: " << task << std::endl;
    }
}
