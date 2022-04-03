#pragma once
#include <iostream> 
#include <vector> 
//#include "Sequence.h"

template<class Key>
class List: public Sequence<Key> {
    public:
        List();
        ~List() = default;
    
        bool Search(const Key& k) const;
        bool Insert(const Key& k);
        bool IsFull() const;
};


template<class Key>
List<Key>::List() {
    int size = Sequence<Key>::sblockSize_;
    Sequence<Key>::sTable_.resize(size);
}

template<class Key>
bool List<Key>::Search(const Key& k) const{

    for (int i = 0; i < Sequence<Key>::sTable_.size(); i++) {

        if (k == Sequence<Key>::sTable_[i]) {
            //std::cout << "[Se encontró en el bloque: " << i;
            return true;
        }
    }

    return false;
}

template<class Key>
bool List<Key>::Insert(const Key& k) {
    //Search(k) Evitar elementos repetidos
    /*if (IsFull()) {
        return false; // fracaso
    }*/

    Sequence<Key>::InsertElement(k);
    return true; // éxito
}

template<class Key>
bool List<Key>::IsFull() const{
    return false;
}


