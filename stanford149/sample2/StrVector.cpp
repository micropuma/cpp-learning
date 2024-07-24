/*
 * Classes lecture code example credit to Sarah McCarthy
 */

// dont forget to include the .h file!
// implementation for strvector.cpp goes here!
#include "StrVector.h"

// StrVector::StrVector() : logicalSize{0}, allocatedSize{kInitialSize} {}

StrVector::StrVector(size_t n, const std::string &val)
    : logicalSize{n}, allocatedSize{n * 2} {
  elems = new std::string[allocatedSize];
  std::fill(begin(), end(), val);
}

StrVector::~StrVector() { delete[] elems; }

StrVector::iterator StrVector::begin() { return elems; }
StrVector::iterator StrVector::end() { return elems + logicalSize; }
StrVector::const_iterator StrVector::cbegin() const { return elems; }
StrVector::const_iterator StrVector::cend() const { return elems + logicalSize; }
StrVector::const_iterator_mutable StrVector::begin_mutable() { return elems; }
StrVector::const_iterator_mutable StrVector::end_mutable() { return elems + logicalSize; }
StrVector::const_const_iterator StrVector::cbegin_const() const { return elems; }
StrVector::const_const_iterator StrVector::cend_const() const { return elems + logicalSize; }

size_t StrVector::size() { return logicalSize; }

bool StrVector::empty() { return logicalSize == 0; }

void StrVector::push_back(const std::string &elem) {
  if (logicalSize == allocatedSize) {
    grow();
  }
  *(begin() + logicalSize) = elem;
  logicalSize++;
}

void StrVector::grow() {
  auto new_elems = new std::string[allocatedSize *= 2];
  for (size_t i = 0; i < logicalSize; i++) {
    *(new_elems + i) = *(begin() + i);
  }
  elems = new_elems;
}

std::string &StrVector::operator[](size_t index) {
  /// TODO
  return elems[index]; 
}

std::string &StrVector::at(size_t index) {
  /// TODO
  if (index > logicalSize) {
    if (index >= logicalSize) {
      throw std::out_of_range("Index out of range");
    }
    return elems[index];
  }
}

