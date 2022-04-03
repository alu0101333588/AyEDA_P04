#pragma one
#include <iostream> 
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

    int GetBlockSize() {return sblockSize_;}
    int GetSizeTable() {return sTable_.size();}
    void SetBlockSize(int bSize) {sblockSize_ = bSize;}
    
    Key GetPosicion(int i) {return sTable_[i];}
    void InsertElement(Key k) {sTable_.push_back(k);}
  
  protected:
    int sblockSize_; // sSize
    std::vector<Key> sTable_; // sequenceTable

};

template<class Key>
void Sequence<Key>::Print() {
  for (int i = 0; i < sTable_.size(); i++) {
    std::cout << sTable_[i] << " ";
  }
}


