#pragma once
#include <iostream> 
#include <list>

template<class Key>
class Sequence {
  public:
    Sequence() {}
    virtual ~Sequence() = default;

    virtual bool Search(const Key& k) const = 0;
    virtual bool Insert(const Key& k) = 0;
    virtual bool IsFull() const = 0;

    int GetBlockSize() {return blockSize_;}
    void SetBlockSize(int bSize) {blockSize_ = bSize;}
    std::list<Key> GetTabla() { return table_;}
    void SetTabla(Sequence<Key> sequence1) {table_ = sequence1;}
  
  protected:
    int blockSize_;
    std::list<Key> table_;
    

  //int get_max_size() const;
  //void set_max_size(const int& max_size);
  //std::vector<Key> get_vector();

 /*private:
  std::vector<Key> table;
  int blockSize;*/
};

