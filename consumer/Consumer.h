//
// Created by focus on 28.10.2021.
//

#ifndef PRODUCE_CONSUMER_H
#define PRODUCE_CONSUMER_H

#include "middleware/Middleware.h"


class Consumer {
public:
    explicit Consumer(MiddlewarePtr mid);

    void run();

private:
    MiddlewarePtr mid_;
};


#endif //PRODUCE_CONSUMER_H
