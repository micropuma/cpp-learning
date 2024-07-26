/*
 * Classes lecture code example credit to Sarah McCarthy
 */

// in case mutliple files in a project include strvector,
// this instruction says only compile this file once!
#ifndef STRVECTOR_H
#define STRVECTOR_H

#include <algorithm>
#include <string>

class StrVector {
public:
  // type alias (this is how iterator types work!)
  using iterator = std::string *;
  using const_iterator = const std::string*;
  using const_iterator_mutable = std::string* const;
  using const_const_iterator = const std::string*;

  const size_t kInitialSize = 2;

  // Constructors & Destructor
  StrVector();
  StrVector(size_t n, const std::string &val);
  ~StrVector();

  // Low hanging fruit
  size_t size();
  bool empty();

  // Adding and Removing Elements from Vector
  void push_back(const std::string &elem);
  std::string &operator[](size_t index);
  std::string &at(size_t index);

  // OUR ITERATORS :)
  iterator begin();
  iterator end();
  // 里面的东西不能修改但是iterator可以移动
  const_iterator cbegin() const;
  const_iterator cend() const;
  // 里面的东西能够修改，但是不能移动iterator
  const_iterator_mutable begin_mutable(); 
  const_iterator_mutable end_mutable(); 
  // 不论是东西，还是移动，都不行
  const_const_iterator cbegin_const() const;
  const_const_iterator cend_const() const;

private:
  size_t logicalSize;
  size_t allocatedSize;
  std::string *elems;
  void grow();
};

#endif // STRVECTOR_H