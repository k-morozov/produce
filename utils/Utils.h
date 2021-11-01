//
// Created by focus on 01.11.2021.
//

#ifndef PRODUCE_UTILS_H
#define PRODUCE_UTILS_H


#include <iostream>
#include <sstream>
#include <mutex>

namespace detail {

class pcout : public std::stringstream
    {
        static inline std::mutex m_;
    public:
        ~pcout() override
        {
            std::lock_guard lck(m_);
            std::cout << rdbuf();
        }
    };
}


#endif //PRODUCE_UTILS_H
