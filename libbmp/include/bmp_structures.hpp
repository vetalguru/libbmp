#ifndef LIBBMP_INCLUDE_BMP_STRUCTURES_HPP_
#define LIBBMP_INCLUDE_BMP_STRUCTURES_HPP_

#include <cstdint>

#include "common.hpp"

namespace Decoder {

struct BITMAP_FILE_HEADER {
  uint16_t bfType{};
  uint32_t bfSize{};
  uint16_t bfReserved1{};
  uint16_t bfReserved2{};
  uint32_t bfOffBits{};

  void changeBytesOrder() {
    bfType = swapBytes_16(bfType);
    bfSize = swapBytes_32(bfSize);
    bfReserved1 = swapBytes_16(bfReserved1);
    bfReserved2 = swapBytes_16(bfReserved2);
    bfOffBits = swapBytes_32(bfOffBits);
  }
};

struct BITMAP_INFO_HEADER {
  uint32_t biSize{};
  int32_t biWidth{};
  int32_t biHeight{};
  uint16_t biPlanes{};
  uint16_t biBitCount{};
  uint32_t biCompression{};
  uint32_t biSizeImage{};
  int32_t biXPelsPerMeter{};
  int32_t biYPelsPerMeter{};
  uint32_t biClrUsed{};
  uint32_t biClrImportant{};

  void changeBytesOrder() {
    biSize = swapBytes_32(biSize);
    biWidth =
        static_cast<int32_t>(swapBytes_32(static_cast<uint32_t>(biWidth)));
    biHeight =
        static_cast<int32_t>(swapBytes_32(static_cast<uint32_t>(biHeight)));
    biPlanes = swapBytes_16(biPlanes);
    biBitCount = swapBytes_16(biBitCount);
    biCompression = swapBytes_32(biCompression);
    biSizeImage = swapBytes_32(biSizeImage);
    biXPelsPerMeter = static_cast<int32_t>(
        swapBytes_32(static_cast<uint32_t>(biXPelsPerMeter)));
    biYPelsPerMeter = static_cast<int32_t>(
        swapBytes_32(static_cast<uint32_t>(biYPelsPerMeter)));
    biClrUsed = swapBytes_32(biClrUsed);
    biClrImportant = swapBytes_32(biClrImportant);
  }
};

} // namespace Decoder

#endif // LIBBMP_INCLUDE_BMP_STRUCTURES_HPP_
