#pragma once
#include <iostream> 
//#include "Sequence.h"
#include "DispersionFunction.h"
#include "ExplorationFunction.h"
#include "Block.h"
//#include "List.h"

#include <vector>

template<class Key> class Sequence;
template<class Key>
class HashTable {
    public:
        HashTable(unsigned tableSize, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe, unsigned blockSize);
        ~HashTable() = default;
        bool Search(const Key& k) const; 
        bool Insert(const Key& k); 

        //void setSequence(Sequence<Key> Sequence1) {table_ = new Sequence1;}
    
        void Print(); 
        int GetSizeTab() const {return tableSize_; }
 
        void EstablishTable(int option);
    
    private:
        unsigned tableSize_; // Tamaño tabla
        std::vector<Sequence<Key>> *table_;

        DispersionFunction<Key> *fd_;
        unsigned blockSize_; // En dispersión abierta = 0
        ExplorationFunction<Key> *fe_; // En dispersión abierta = nullptr
    
};

template<class Key>
void HashTable<Key>::EstablishTable(int option) {
    if (option == 1) {
        for (int i = 0; i < table_->size(); i++) {
            table_[i] = new Block<Key>(blockSize_);
        }
        
    } else {
        for (int i = 0; i < table_->size(); i++) {
            table_[i] = new Block<Key>(blockSize_); // List<Key>
        }
    }
}

template<class Key>
HashTable<Key>::HashTable(unsigned tableSize, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe, unsigned blockSize) {
    tableSize_ = tableSize;
    fd_ = fd;
    fe_ = fe;
    blockSize_ = blockSize;
    //table_.resize(tableSize);


}

template<class Key>
bool HashTable<Key>::Search(const Key& k) const {

    for (int i = 0; i < table_->size(); i++) {
        if (table_[i].Search(k)) {
            return true;
        }
    }

    return false;
}

template<class Key>
bool HashTable<Key>::Insert(const Key& k) {

    unsigned posicion = fd_->operator()(k);
    //fd_()(k);

    if (!(table_[posicion].Insert(k))) { // Cerrada
        bool exito = false;
        unsigned iteracion = 1;
        while (!exito) {
            int posicion2 = fe_->operator()(k, iteracion);
            if (table_[posicion2].Insert(k)) {
                exito = true;
                return true;
            }
            iteracion++;
        }
    } else { // Abierta
        return true;
    }

    return false;
}

template<class Key>
void HashTable<Key>::Print() {
    for (int i = 0; i < table_->size(); i++) {
        std::cout << i << ": ";
        table_[i].Print();
        std::cout << std::endl; 
    }

}