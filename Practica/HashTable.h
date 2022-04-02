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

        //void setSequence(Sequence<Key> Sequence1) {table_ = new Sequence1;}
    
        void Print(); 
        int GetSizeTab() const {return tableSize_; }
 
        void EstablishTable(int option);
    
    private:
        int tableSize_; // Tamaño tabla
        std::list<Sequence<Key>> *table_; 
        DispersionFunction<Key> *fd_;
        int blockSize_; // En dispersión abierta = 0
        ExplorationFunction<Key> *fe_; // En dispersión abierta = nullptr
    
};

template<class Key>
void HashTable::EstablishTable(int option) {
    if (option == 1) {
        table_->SetTable(new Block<Key>);
    } else {
        table_->SetTable(new List<Key>);
    }
}

template<class Key>
HashTable::HashTable(int tableSize, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe, int blockSize) {
    tableSize_ = tableSize;
    fd_ = fd;
    fe_ = fe;
    blockSize_ = blockSize;
    table_.resize(tableSize);


}

template<class Key>
bool HashTable::Search(const Key& k) const {

    std::list<std::Sequence<Key>>::iterator it = table_.begin();
    int i = -1;
    while (i < table_.size()) { // !match &&  
        i++;
        if (table_.at(i).Search(k)) {
            return true;
        }
    }

    return false;
}

template<class Key>
bool Insert(const Key& k) {

    unsigned posicion = fd_()(k);

    if (!(table_.at(posicion).Insert(k))) { // Cerrada
        bool exito = false;
        unsigned iteracion = 1;
        while (!exito) {
            unsigned posicion2 = fe_(k, iteracion);
            if (table_.at(posicion2).Insert(k)) {
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
void HashTable::Print() {
    for (int i = 0; i < table_.size(); i++) {
        std::cout << i << ": ";
        table_.at(i).Print();
        std::cout << std::endl;
        /*for (int j = 0; j < table_.at(i).GetSizeTable(); j++) {
            std::cout << table_.at(i).at(j) << " ";
        }*/
        
    }

}