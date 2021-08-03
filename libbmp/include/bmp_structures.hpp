#ifndef LIBBMP_INCLUDE_BMP_STRUCTURES_HPP_
#define LIBBMP_INCLUDE_BMP_STRUCTURES_HPP_

#include <cstdint>

namespace Decoder {

struct BITMAP_FILE_HEADER {
  uint16_t bfType;
  uint32_t bfSize;
  uint16_t bfReserved1;
  uint16_t bfReserved2;
  uint32_t bfOffBits;
};

struct BITMAP_INFO_HEADER {
  uint32_t biSize;
  int32_t biWidth;
  int32_t biHeight;
  uint16_t biPlanes;
  uint16_t biBitCount;
  uint32_t biCompression;
  uint32_t biSizeImage;
  int32_t biXPelsPerMeter;
  int32_t biYPelsPerMeter;
  uint32_t biClrUsed;
  uint32_t biClrImportant;
};

} // namespace Decoder

#endif // LIBBMP_INCLUDE_BMP_STRUCTURES_HPP_
