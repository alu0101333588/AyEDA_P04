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


    void Print();

    int GetBlockSize() {return blockSize_;}
    int GetSizeTable() {return table_.size();}
    void SetBlockSize(unsigned bSize) {blockSize_ = bSize;}
    std::list<Key> GetTable() { return table_;}
    void SetTable(Sequence<Key>* sequence1) {table_ = sequence1;}
    
  
  protected:
    unsigned blockSize_;
    std::list<Key> table_;
    

  //int get_max_size() const;
  //void set_max_size(const int& max_size);
  //std::vector<Key> get_vector();

 /*private:
  std::vector<Key> table;
  int blockSize;*/
};

template<class Key>
void Sequence<Key>::Print() {
  for (int i = 0; i < table_.size(); i++) {
    std::cout << i << " ";
  }
}


