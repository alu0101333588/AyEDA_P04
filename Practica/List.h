#pragma once
#include <iostream> 
#include <list> 
#include "Sequence.h"

template<class Key>
class List: public Sequence {
    public:
        List(unsigned blockSize);
        ~List() = default;
    
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
List<Key>::List(unsigned blockSize) {
    std::cout << "EN PRUEBAS" << std::endl;
    //SetBlockSize(blockSize);
    //table_.resize(blockSize);
}

template<class Key>
bool List<Key>::Search(const Key& k) const{
    std::cout << "EN PRUEBAS" << std::endl;
    //bool match = false;
    /*std::list<std::vector<double>>::iterator it = table_.begin();
    int i = -1;
    while (i < GetBlockSize()) { // !match &&  
        i++;
        if (k == it->at(i)) {
            //coincidencia = true;
            return true;
        }
    }*/

    return false;
    //return match;
}

template<class Key>
bool List<Key>::Insert(const Key& k) const{    
    
    std::cout << "EN PRUEBAS" << std::endl;
    /*if (Search(k) || IsFull()) {
        return false;
    }

    table_.push_back(k);*/
    return true;
}

template<class Key>
bool List<Key>::IsFull() const{
    std::cout << "EN PRUEBAS" << std::endl;
    /*if (table_.size() == GetBlockSize()) {
        return true;
    }*/

    return false;
}