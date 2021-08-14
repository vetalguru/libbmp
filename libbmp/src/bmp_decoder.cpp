#include "bmp_decoder.hpp"

#include "algorithm"
#include <cstdlib>
#include <fstream>

#include "bmp_structures.hpp"
#include "common.hpp"
#include "unused.hpp"

using namespace Decoder;

BmpDecoder::BmpDecoder(const std::string &aFileName)
    : m_isValid{false}, m_fileSize{0}, m_bitsOffset{0}, m_infoStructSize{0},
      m_bitCount{0} {
  m_isValid = parseFile(aFileName);
}

BmpDecoder::~BmpDecoder() {}

bool BmpDecoder::isValid() const { return m_isValid; }

uint32_t BmpDecoder::fileSizeFromHeader() const { return m_fileSize; }

uint32_t BmpDecoder::bitOffset() const { return m_bitsOffset; }

uint32_t BmpDecoder::infoStructureSize() const { return m_infoStructSize; }

uint32_t BmpDecoder::width() const {
  return static_cast<uint32_t>(m_bitmap[0].size());
}

uint32_t BmpDecoder::height() const {
  return static_cast<uint32_t>(m_bitmap.size());
}

uint16_t BmpDecoder::bitCount() const { return m_bitCount; }

bool BmpDecoder::pixelColor(const uint32_t aX, const uint32_t aY,
                            PixelColor &aPixelColor) const {
  if (aX >= width() || aY >= height())
    return false;

  aPixelColor = m_bitmap[aX][aY];

  return true;
}

bool BmpDecoder::parseFile(const std::string &aFileName) {
  if (aFileName.empty())
    return false;

  std::ifstream bmp_stream(aFileName, std::ios::binary);
  if (!bmp_stream || bmp_stream.fail())
    return false;

  BITMAP_FILE_HEADER bmpFileHeader;
  if (!decodeBitmapFileHeader(bmp_stream, bmpFileHeader))
    return false;

  m_fileSize = bmpFileHeader.bfSize;
  m_bitsOffset = bmpFileHeader.bfOffBits;

  BITMAP_INFO_HEADER bmpInfoHeader;
  if (!decodeBitmapInfoHeader(bmp_stream, bmpInfoHeader))
    return false;

  // FIXME: Supported only 24 bit bitmap
  if (bmpInfoHeader.biBitCount != 24)
    return false;

  m_infoStructSize = bmpInfoHeader.biSize;
  auto width = static_cast<uint32_t>(bmpInfoHeader.biWidth);
  auto height = static_cast<uint32_t>(abs(bmpInfoHeader.biHeight));
  m_bitCount = bmpInfoHeader.biBitCount;

  const unsigned bytesPerPixel = bmpInfoHeader.biBitCount >> 3;
  const unsigned padding = 4 - ((width * bytesPerPixel) % 4);

  bmp_stream.seekg(m_bitsOffset, std::ios::beg);

  for (uint32_t i = 0; i < height; ++i) {
    std::vector<PixelColor> row;

    for (uint32_t j = 0; j < width; ++j) {
      PixelColor color;
      readFromStream(bmp_stream, color.Blue);
      readFromStream(bmp_stream, color.Green);
      readFromStream(bmp_stream, color.Red);

      row.push_back(color);
    }

    m_bitmap.push_back(row);

    for (unsigned p = 0; p < padding; ++p) {
      uint8_t tmpByte = 0;
      readFromStream(bmp_stream, tmpByte);
    }
  }

  if (bmpInfoHeader.biHeight > 0)
    std::reverse(m_bitmap.begin(), m_bitmap.end());

  return true;
}

bool BmpDecoder::decodeBitmapFileHeader(std::ifstream &aStream,
                                        BITMAP_FILE_HEADER &aFileHeader) {
  if (!aStream)
    return false;

  readFromStream(aStream, aFileHeader.bfType);
  readFromStream(aStream, aFileHeader.bfSize);
  readFromStream(aStream, aFileHeader.bfReserved1);
  readFromStream(aStream, aFileHeader.bfReserved2);
  readFromStream(aStream, aFileHeader.bfOffBits);

  if (isBigEndian())
    aFileHeader.changeBytesOrder();

  return true;
}

bool BmpDecoder::decodeBitmapInfoHeader(std::ifstream &aStream,
                                        BITMAP_INFO_HEADER &aInfoHeader) {
  if (!aStream)
    return false;

  readFromStream(aStream, aInfoHeader.biSize);
  readFromStream(aStream, aInfoHeader.biWidth);
  readFromStream(aStream, aInfoHeader.biHeight);
  readFromStream(aStream, aInfoHeader.biPlanes);
  readFromStream(aStream, aInfoHeader.biBitCount);
  readFromStream(aStream, aInfoHeader.biCompression);
  readFromStream(aStream, aInfoHeader.biSizeImage);
  readFromStream(aStream, aInfoHeader.biXPelsPerMeter);
  readFromStream(aStream, aInfoHeader.biYPelsPerMeter);
  readFromStream(aStream, aInfoHeader.biClrUsed);
  readFromStream(aStream, aInfoHeader.biClrImportant);

  if (isBigEndian())
    aInfoHeader.changeBytesOrder();

  return true;
}
