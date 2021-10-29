//
// Created by focus on 29.10.2021.
//

#ifndef PRODUCE_MIDDLEWARE_H
#define PRODUCE_MIDDLEWARE_H


#include <cstdlib>
#include <queue>
#include <mutex>
#include <condition_variable>


class Middleware;
using  MiddlewarePtr = std::shared_ptr<Middleware>;


class Middleware {
    using Task = size_t;
public:
    explicit Middleware(std::condition_variable &, std::condition_variable &);

    void addTask(Task task, bool isFinished = false);
    Task popTask();

public:
    [[nodiscard]]
    std::mutex &getM();

    bool isFinished() const;
    auto emptyTasks() const { return tasks_.empty(); }
private:
    void notifyProducer();
    void notifyConsumer();

public:
    std::condition_variable &getGoProduce();
    std::condition_variable &getGoConsume();

private:
    std::condition_variable & goProduce_;
    std::condition_variable & goConsume_;

    std::queue<Task> tasks_;
    mutable std::mutex m_;

private:
    bool isFinished_ = false;
};


#endif //PRODUCE_MIDDLEWARE_H
