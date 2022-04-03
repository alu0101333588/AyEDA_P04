#pragma once
#include <iostream> 

template<class Key>
class ExplorationFunction {
    public:
        virtual unsigned operator() (const Key& k, unsigned i) const = 0;
};