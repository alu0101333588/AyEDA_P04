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
            return true;
        }
    }

    return false;
}

template<class Key>
bool Block<Key>::Insert(const Key& k) {
    //Search(k)
    if (IsFull()) {
        return false; // fracaso
    }

    Sequence<Key>::InsertElement(k);
    //Sequence<Key>::table_.push_back(k);
    // no hacer resize
    // hacer push_back siempre y cuando la dimension 
    // del vector no sea superior a la dimension permitida 
    // del bloque
    return true; // éxito
}

template<class Key>
bool Block<Key>::IsFull() const{

    int sizeBlock_act = Sequence<Key>::sTable_.size();
    int sizeBlock_max = Sequence<Key>::sblockSize_;
    //std::cout << "Tamaño tabla " << sizeBlock_act << "Tamaño máximo " << sizeBlock_act << std::endl;

    if (sizeBlock_act == sizeBlock_max) {
        if (Sequence<Key>::sTable_[0] == ' '){
            //std::cout << "PUEDE QUE SÍ" << std::endl;
            return false;
        }
        return true;
    }

    return false;
}


