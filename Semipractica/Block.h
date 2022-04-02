#pragma once
#include <iostream> 
#include <vector> 
#include "Sequence.h"

template<class Key>
class Block: public Sequence<Key> {
    public:
        Block(unsigned blockSize);
        ~Block() = default;
    
        bool Search(const Key& k) const;
        bool Insert(const Key& k);
        bool IsFull() const;
};


template<class Key>
Block<Key>::Block(unsigned blockSize) {
    Sequence<Key>::SetBlockSize(blockSize);
    Sequence<Key>::sTable_.resize(blockSize);
}

template<class Key>
bool Block<Key>::Search(const Key& k) const{

    for (int i = 0; i < Sequence<Key>::GetBlockSize(); i++) {
        if (k == Sequence<Key>::GetPosicion(i)) {
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

    if (Sequence<Key>::GetSizeTable() == Sequence<Key>::GetBlockSize()) {
        return true;
    }

    return false;
}
