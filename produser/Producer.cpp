//
// Created by focus on 28.10.2021.
//

#include "Producer.h"

Producer::Producer(MiddlewarePtr mid) :
    mid_(std::move(mid))
{

}

void Producer::run()
{
    for(size_t i=0; i<10; ++i)
    {
        {
            std::unique_lock lck(mid_->getM());

            mid_->getGoProduce().wait(lck,
                                      [] { return true; }
            );
            mid_->addTask(i);
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1s);
    }

    std::unique_lock lck(mid_->getM());
    mid_->addTask(10, true);
}
