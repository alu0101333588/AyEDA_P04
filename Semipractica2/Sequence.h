#pragma one
#include <iostream> 
#include <list>
#include <vector>

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
    int GetSizeTable() {return sTable_.size();}
    void SetBlockSize(unsigned bSize) {blockSize_ = bSize;}
    
    std::list<Key> GetTable() { return sTable_;}
    Key GetPosicion(int i) {return sTable_[i];}
    void InsertElement(Key k) {sTable_.push_back(k);}
  
  protected:
    unsigned blockSize_;
    std::vector<Key> sTable_; // sequenceTable

};

template<class Key>
void Sequence<Key>::Print() {
  for (int i = 0; i < sTable_.size(); i++) {
    std::cout << i << " ";
  }
}


