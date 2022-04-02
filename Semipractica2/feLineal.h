#pragma once
#include <iostream> 
#include "ExplorationFunction.h"

template<class Key>
class feLineal: public ExplorationFunction<Key> {
    public:
        unsigned operator() (const Key& k, unsigned i) const {
            return i;
        }
};

