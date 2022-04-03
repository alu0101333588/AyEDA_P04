#pragma once
#include <iostream> 
#include <vector> 
#include "Sequence.h"

template<class Key>
class Block: public Sequence<Key> {
    public:
        Block();
        ~Block() = default;
    
        bool Search(const Key& k) const;
        bool Insert(const Key& k);
        bool IsFull() const;
};


template<class Key>
Block<Key>::Block() {
    int size = Sequence<Key>::sblockSize_;
    Sequence<Key>::sTable_.resize(size);
}

template<class Key>
bool Block<Key>::Search(const Key& k) const{

    for (int i = 0; i < Sequence<Key>::sTable_.size(); i++) {

        if (k == Sequence<Key>::sTable_[i]) {
            //std::cout << "[Se encontró en el bloque: " << i;
            return true;
        }
    }

    return false;
}

template<class Key>
bool Block<Key>::Insert(const Key& k) {
    //Search(k) Evitar elementos repetidos
    if (IsFull()) {
        return false; // fracaso
    }

    Sequence<Key>::InsertElement(k);
    return true; // éxito
}

template<class Key>
bool Block<Key>::IsFull() const{

    int sizeBlock_act = Sequence<Key>::sTable_.size();
    int sizeBlock_max = Sequence<Key>::sblockSize_;

    if (sizeBlock_act == sizeBlock_max) {
        if (Sequence<Key>::sTable_[0] == ' '){
            return false;
        }
        return true;
    }

    return false;
}


