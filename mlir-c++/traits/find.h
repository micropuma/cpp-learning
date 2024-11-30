#pragma once

template<class inputIterator, class T>
inputIterator find(inputIterator first, inputIterator last, const T& value) {
    while (first != last && *first != value) {
        ++first;
    }
    return last;
}   // namespace mlir