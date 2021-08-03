#ifndef LIBBMP_INCLUDE_BMP_STRUCTURES_HPP_
#define LIBBMP_INCLUDE_BMP_STRUCTURES_HPP_

#include <cstdint>

namespace Decoder {

// Bitmap file header
struct BITMAP_FILE_HEADER {
  uint16_t bfType;
  uint32_t bfSize;
  uint16_t bfReserved1;
  uint16_t bfReserved2;
  uint32_t bfOffBits;
};

} // namespace Decoder

#endif // LIBBMP_INCLUDE_BMP_STRUCTURES_HPP_
