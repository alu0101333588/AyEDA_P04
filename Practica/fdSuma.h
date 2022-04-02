#pragma once
#include <iostream> 
#include "DispersionFunction.h"

template<class Key>
class fdSuma: public DispersionFunction<Key> {
    public:
        fdSuma(const unsigned n): tableSize_(n) {}
        unsigned operator() (const Key& k) const {
            return k % tableSize_;
        }
    private:
        unsigned tableSize_;
};
