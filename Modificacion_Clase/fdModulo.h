#pragma once
#include <iostream> 
#include "DispersionFunction.h"

template<class Key>
class fdModulo: public DispersionFunction<Key> {
    public:
        fdModulo(const unsigned n): tableSize_(n) {}
        unsigned operator() (const Key& k) const {
            return k % tableSize_;
        }
    private:
        unsigned tableSize_;
};

