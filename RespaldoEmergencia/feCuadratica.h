#pragma once
#include <iostream> 
#include "ExplorationFunction.h"
#include <math.h>

template<class Key>
class feCuadratica: public ExplorationFunction<Key> {
    public:
        unsigned operator() (const Key& k, unsigned i) const {
            return pow(i, 2);
        }
};

