//
// Created by focus on 28.10.2021.
//

#ifndef PRODUCE_PRODUCER_H
#define PRODUCE_PRODUCER_H

#include <thread>
#include <queue>
#include <vector>
#include "../middleware/Middleware.h"


class Producer {
    using Task = size_t;
public:
    explicit Producer(MiddlewarePtr mid);

    void run();
private:
    MiddlewarePtr mid_;
};


#endif //PRODUCE_PRODUCER_H
