#pragma once
#include <iostream> 
#include <list> 
#include "Sequence.h"

template<class Key>
class Block: public Sequence {
    public:
    Block() {}
    virtual ~Block() = default;
    
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