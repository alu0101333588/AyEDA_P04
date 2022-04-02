#pragma once
#include <iostream> 

template<class Key>
class DispersionFunction {
    public:
        virtual unsigned operator() (const Key& k) const = 0;
};