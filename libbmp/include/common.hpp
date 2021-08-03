#ifndef LIBBMP_INCLUDE_COMMON_HPP_
#define LIBBMP_INCLUDE_COMMON_HPP_

#include "fstream"

template <typename T>
inline void readFromStream(std::ifstream &aStream, T &aType) {
  aStream.read(reinterpret_cast<char *>(&aType), sizeof(T));
}

#endif // LIBBMP_INCLUDE_COMMON_HPP_
