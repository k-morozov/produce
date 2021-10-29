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
    Consumer consumer(mid);

    auto firstConsumer = std::async(std::launch::async, [&consumer](){ consumer.run(); });
    auto secondConsumer = std::async(std::launch::async, [&consumer](){ consumer.run(); });
    auto thirdConsumer = std::async(std::launch::async, [&consumer](){ consumer.run(); });
    auto fourthConsumer = std::async(std::launch::async, [&consumer](){ consumer.run(); });
    auto fiveConsumer = std::async(std::launch::async, [&consumer](){ consumer.run(); });

    auto firstProducer = std::async(std::launch::async, [&mid](){
        Producer producer(mid);
        producer.run();
    });
    auto secondProducer = std::async(std::launch::async, [&mid](){
        Producer producer(mid);
        producer.run();
    });
    auto thirdProducer = std::async(std::launch::async, [&mid](){
        Producer producer(mid);
        producer.run();
    });

    return 0;
}
