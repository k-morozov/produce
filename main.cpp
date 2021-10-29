#include <iostream>
#include <future>

#include "middleware/Middleware.h"
#include "produser/Producer.h"
#include "consumer/Consumer.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    std::condition_variable goProduce;
    std::condition_variable goConsume;

    auto mid = std::make_shared<Middleware>(goProduce, goConsume);
    Producer producer(mid);
    Consumer consumer(mid);

    auto future = std::async(std::launch::async, [&consumer](){ consumer.run(); });
    producer.run();

    return 0;
}
