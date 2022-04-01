#pragma once
#include <iostream> 
#include <list> 
#include "Sequence.h"
#include "DispersionFunction.h"
#include "ExplorationFunction.h"
//#include "funciondispersion.hpp"
//#include "funcionexploracion.hpp"
//#include "vector.hpp"

//#include <vector>

template<class Key>
class HashTable {
    public:
    HashTable(int tableSize, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe, int blockSize);
    ~HashTable() {};
    bool Search(const Key& k) const; 
    bool Insert(const Key& k); 
    
    void Print();
    int GetSize() const;
    
    private:
    int tableSize_; // Tamaño tabla
    std::list<Sequence<Key>> table_; 
    DispersionFunction<Key> *fd_;
    int blockSize_; // En dispersión abierta = 0
    ExplorationFunction<Key> *fe_; // En dispersión abierta = nullptr
    
};
