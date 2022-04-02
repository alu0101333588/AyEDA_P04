#pragma once
#include <iostream> 
#include <list> 
#include "Sequence.h"
#include "DispersionFunction.h"
#include "ExplorationFunction.h"
#include "Sequence.h"
#include "Block.h"
#include "List.h"

//#include <vector>

template<class Key>
class HashTable {
    public:
        HashTable(int tableSize, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe, int blockSize);
        ~HashTable() {};
        bool Search(const Key& k) const; 
        bool Insert(const Key& k); 

        void setSequence(Sequence<Key> Sequence1) {table_ = new Sequence1;}
    
        void Print(); 
        int GetSize() const;

        void EstablishTable(int option);
    
    private:
        int tableSize_; // Tamaño tabla
        std::list<Sequence<Key>> table_; 
        DispersionFunction<Key> *fd_;
        int blockSize_; // En dispersión abierta = 0
        ExplorationFunction<Key> *fe_; // En dispersión abierta = nullptr
    
};

template<class Key>
void HashTable::EstablishTable(int option) {
    if (option == 1) {
        table_.SetTabla(new Block<Key>);
    } else {
        table_.SetTabla(new List<Key>);
    }
}