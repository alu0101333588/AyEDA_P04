#pragma once
#include <iostream> 
#include "DispersionFunction.h"
#include <stdlib.h> // srand, rand

template<class Key>
class fdPseudoaleatoria: public DispersionFunction<Key> {
    public:
        fdPseudoaleatoria(const unsigned n): tableSize_(n) {}
        unsigned operator() (const Key& k) const {
            srand(k);
            return rand() % tableSize_;
        }
    private:
        unsigned tableSize_;
};

