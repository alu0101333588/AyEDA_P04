#pragma once
#include <iostream> 
#include <list> 
#include "Sequence.h"

template<class Key>
class Sequence {
    public:
    Sequence() {}
    virtual ~Sequence() = default;
    
    virtual bool Search(const Key& k) const = 0;
    virtual bool Insert(const Key& k) = 0;
    virtual bool IsFull() const = 0;
    
    //int get_max_size() const;
    //void set_max_size(const int& max_size);
    //std::vector<Key> get_vector();
    
    private:
    std::list<> table;
    //list<std::vector<double>>
    //std::vector<Key> table;
    int tableSize;
    int blockSize;
};