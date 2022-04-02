#pragma once
#include <iostream> 
#include "ExplorationFunction.h"
#include <stdlib.h> // srand, rand

template<class Key>
class feRedispersion: public ExplorationFunction<Key> {
    public:
        unsigned operator() (const Key& k, unsigned i) const {
            srand(k);
            int resultado = 0;
            for (int j = 0; j < i; j++) {
                resultado = rand();
            }
            return resultado;
        }

};

