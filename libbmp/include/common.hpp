#ifndef LIBBMP_INCLUDE_COMMON_HPP_
#define LIBBMP_INCLUDE_COMMON_HPP_

#include "fstream"

inline bool isBigEndian() {
  uint16_t x = 0x0001;
  return static_cast<uint8_t>(x) == 0;
}

inline uint16_t swapBytes_16(const uint16_t &aData) {
  return static_cast<uint16_t>(aData >> 8 | aData << 8);
}

inline uint32_t swapBytes_32(const uint32_t &aData) {
  return (((aData >> 24) & 0xFF) | ((aData << 8) & 0xFF0000) |
          ((aData >> 8) & 0xFF00) | ((aData << 24) & 0xFF000000));
}

template <typename T>
inline void readFromStream(std::ifstream &aStream, T &aType) {
  aStream.read(reinterpret_cast<char *>(&aType), sizeof(T));
}

#endif // LIBBMP_INCLUDE_COMMON_HPP_
