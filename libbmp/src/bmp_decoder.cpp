#include "bmp_decoder.hpp"

#include <cstdlib>
#include <fstream>

#include "bmp_structures.hpp"
#include "common.hpp"
#include "unused.hpp"

using namespace Decoder;

BmpDecoder::BmpDecoder(const std::string &aFileName)
    : m_isValid{false}, m_fileSize{0}, m_bitsOffset{0}, m_infoStructSize{0},
      m_bitCount{0}, m_width{0}, m_height{0} {
  m_isValid = parseFile(aFileName);
}

BmpDecoder::~BmpDecoder() {}

bool BmpDecoder::isValid() const { return m_isValid; }

uint32_t BmpDecoder::fileSizeFromHeader() const { return m_fileSize; }

uint32_t BmpDecoder::bitOffset() const { return m_bitsOffset; }

uint32_t BmpDecoder::infoStructureSize() const { return m_infoStructSize; }

int32_t BmpDecoder::width() const { return abs(m_width); }

int32_t BmpDecoder::height() const { return abs(m_height); }

uint16_t BmpDecoder::bitCount() const { return m_bitCount; }

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
  m_width = bmpInfoHeader.biWidth;
  m_height = bmpInfoHeader.biHeight;
  m_bitCount = bmpInfoHeader.biBitCount;

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

  return true;
}
