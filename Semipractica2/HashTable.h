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
        //std::vector<Sequence<Key>> *table_;
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

        

        /*std::cout << "INFORME 1" << std::endl;
        
        std::cout << "INFORME 2" << std::endl;
        table2_[0] = new Block<Key>[1];
        std::cout << "INFORME 3" << std::endl;
        //bool prueba1 = table2_[0]->Insert(k);
        bool prueba1 = true;
        std::cout << "INFORME 4. " << prueba1 << std::endl;
        table2_[0]->SetBlockSize(4);
        std::cout << "INFORME 5" << std::endl;
        Key elemento2 = 42;
        bool verifica2 = table2_[0]->Insert(elemento2);
        elemento2 = 50;
        bool verifica3 = table2_[0]->Insert(elemento2);
        std::cout << "INFORME 6" << std::endl;
        std::cout << "INFORMEEEE " << table2_[0]->GetPosicion(0) << std::endl;
        std::cout << "INFORMEEEE " << table2_[0]->GetPosicion(1) << std::endl;*/
        
    } else {
        std::cout << "TEMPORAL" << std::endl;
        
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
            return true;
        }
    }

    return false;
}

template<class Key>
bool HashTable<Key>::Insert(const Key& k) {

    unsigned posicion = fd_->operator()(k);

    bool verifica = table_[posicion]->Insert(k);
    //std::cout << "[OUT] Posicion solicita " << posicion << std::endl;
    

    if (!verifica) { // Cerrada
        //std::cout << "BARRERA --" << std::endl;
        bool exito = false;
        unsigned iteracion = 0;
        while (!exito) {
            int posicion2 = fe_->operator()(k, iteracion);
            if (posicion2 >= tableSize_) {
                return false;
            }
            std::cout << "solicita posición: " << posicion2 << std::endl;
            verifica = table_[posicion2]->Insert(k);
            if (verifica) {
                std::cout << "Se ha insertado en la posición " << posicion2 << ". it: " << iteracion << std::endl;
                exito = true;
                return true;
            }
            std::cout << "iteraciones " << iteracion << std::endl;
            iteracion++;
        }
    } else { // Abierta
        std::cout << "Se ha insertado en la posición " << posicion << ". SIN it" << std::endl;
        return true;
    }

    return false;
}

template<class Key>
void HashTable<Key>::Print() {
    for (int i = 0; i < tableSize_; i++) {
        std::cout << i << ": ";
        table_[i]->Print();
        std::cout << std::endl; 
    }

}