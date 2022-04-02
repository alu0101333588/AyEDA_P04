#pragma once
#include <iostream> 
#include "DispersionFunction.h"

template<class Key>
class fdSuma: public DispersionFunction<Key> {
    public:
        fdSuma(const unsigned n): tableSize_(n) {}
        unsigned operator() (const Key& k) const {
            /*Key d;
            Key x = k;
            Key y, d;
            while (valor > 0) {
                y = x % 10;
                d = d + y;
                x = x / 10;
            }

            return (d % tableSize_);*/

            return k % tableSize_;
        }
    private:
        unsigned tableSize_;
};
