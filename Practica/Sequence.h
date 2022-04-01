#pragma once
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
  
  protected:
    std::list<Key> table_;
    int blockSize_;

  //int get_max_size() const;
  //void set_max_size(const int& max_size);
  //std::vector<Key> get_vector();

 /*private:
  std::vector<Key> table;
  int blockSize;*/
};