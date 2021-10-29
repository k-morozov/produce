//
// Created by focus on 29.10.2021.
//

#include "Middleware.h"


Middleware::Middleware(std::condition_variable & produce, std::condition_variable & consumer) :
    goProduce_(produce),
    goConsume_(consumer)
{

}

void Middleware::addTask(Task task, bool isFinished)
{
    tasks_.push(task);
    isFinished_ = isFinished;

    notifyConsumer();
}

Middleware::Task Middleware::popTask()
{
    auto task = tasks_.front();
    tasks_.pop();
    notifyProducer();
    return task;
}

void Middleware::notifyProducer()
{
    goProduce_.notify_all();
}

void Middleware::notifyConsumer()
{
    goConsume_.notify_all();
}

std::condition_variable &Middleware::getGoProduce()
{
    return goProduce_;
}

std::condition_variable &Middleware::getGoConsume()
{
    return goConsume_;
}

std::mutex &Middleware::getM()
{
    return m_;
}

bool Middleware::isFinished() const {
    return isFinished_;
}
