#pragma once
#include <iostream> 
#include <list> 
#include "Sequence.h"

template<class Key>
class Block: public Sequence {
    public:
        Block(unsigned blockSize);
        ~Block() = default;
    
        bool Search(const Key& k) const;
        bool Insert(const Key& k);
        bool IsFull() const;

    
    //int get_max_size() const;
    //void set_max_size(const int& max_size);
    //std::vector<Key> get_vector();
    
    //private:
    //std::list<> table;
    //list<std::vector<double>>
    //std::vector<Key> table;
    //int tableSize;
    //int blockSize;
};


template<class Key>
Block<Key>::Block(unsigned blockSize) {
    SetBlockSize(blockSize);
    table_.resize(blockSize);
}

template<class Key>
bool Block<Key>::Search(const Key& k) const{

    std::list<std::Sequence<Key>>::iterator it = table_.begin();
    int i = -1;
    while (i < GetBlockSize()) {   
        i++;
        if (k == it->at(i)) {
            //coincidencia = true;
            return true;
        }
    }

    return false;
}

template<class Key>
bool Block<Key>::Insert(const Key& k) const{
    //Search(k)
    if (IsFull()) {
        return false; // fracaso
    }

    table_.push_back(k);
    return true; // éxito
}

template<class Key>
bool Block<Key>::IsFull() const{

    if (table_.size() == GetBlockSize()) {
        return true;
    }

    return false;
}