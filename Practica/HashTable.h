#pragma once
#include <iostream> 
//#include "Sequence.h"
#include "DispersionFunction.h"
#include "ExplorationFunction.h"
#include "Block.h"
#include "List.h"

#include <vector>

template<class Key> class Sequence;
template<class Key>
class HashTable {
    public:
        HashTable(unsigned tableSize, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe, unsigned blockSize);
        ~HashTable() = default;
        bool Search(const Key& k) const; 
        bool Insert(const Key& k); 
    
        void Print(); 
        int GetSizeTab() const {return tableSize_; }
 
        void EstablishTable(int option); // Establece el tipo: Block / List
    
    private:
        unsigned tableSize_; // Tamaño tabla
        Sequence<Key> **table_;
        DispersionFunction<Key> *fd_; 
        unsigned blockSize_; // En dispersión abierta = 0
        ExplorationFunction<Key> *fe_; // En dispersión abierta = nullptr
    
};

template<class Key>
void HashTable<Key>::EstablishTable(int option) {
    int size = tableSize_;
    table_ = new Sequence<Key>*[size];

    if (option == 1) {

        int blockSize = blockSize_;
        for (int i = 0; i < size; i++) {
            table_[i] = new Block<Key>[1];
            table_[i]->SetBlockSize(blockSize);
        }
       
    } else {
        for (int i = 0; i < size; i++) {
            table_[i] = new List<Key>[1];
        }
        //std::cout << "TEMPORAL" << std::endl;
        
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

    for (int i = 0; i < tableSize_; i++) {
        bool verificacion = table_[i]->Search(k);
        if (verificacion) {
            //std::cout << " (columna: " << i << ")]" << std::endl;
            return true;
        }
    }

    return false;
}

template<class Key>
bool HashTable<Key>::Insert(const Key& k) {

    unsigned posicion = fd_->operator()(k);

    bool verifica = table_[posicion]->Insert(k);
    

    if (!verifica) { // Cerrada
        bool exito = false;
        unsigned iteracion = 0;
        while (!exito) {
            int posicion2 = fe_->operator()(k, iteracion);
            if (posicion2 >= tableSize_) {
                return false;
            }
            verifica = table_[posicion2]->Insert(k);
            if (verifica) {
                exito = true;
                std::cout << "Se ha insertado en la posición " << posicion2 << ". it: " << iteracion << std::endl;
                return true;
            }
            iteracion++;
        }
    } else { // Abierta
        std::cout << "Se ha insertado en la posición " << posicion << ". (SIN it)" << std::endl;
        return true;
    }

    return false;
}

template<class Key>
void HashTable<Key>::Print() {
    for (int i = 0; i < tableSize_; i++) {
        std::cout << i << ": ";
        table_[i]->Print(); // Imprime los bloques
        std::cout << std::endl; 
    }

}