#pragma once
#include <iostream> 
#include "ExplorationFunction.h"
#include "DispersionFunction.h"

template<class Key>
class feDobleDispersion: public ExplorationFunction<Key> {
    public:
        feDobleDispersion (DispersionFunction<Key> *fd) {fd_ = fd;}
        unsigned operator() (const Key& k, unsigned i) const {
            return fd_->operator()(k)*i;
        }
    private: 
        DispersionFunction<Key> *fd_;

};

