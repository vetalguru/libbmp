#include "bmp_decoder.hpp"

#include <fstream>

#include "bmp_structures.hpp"
#include "common.hpp"
#include "unused.hpp"

using namespace Decoder;

BmpDecoder::BmpDecoder(const std::string &aFileName)
    : m_isValid{false}, m_fileSize{0}, m_bitsOffset{0} {
  m_isValid = parseFile(aFileName);
}

BmpDecoder::~BmpDecoder() {}

bool BmpDecoder::isValid() const { return m_isValid; }

uint32_t BmpDecoder::fileSizeFromHeader() const { return m_fileSize; }

uint32_t BmpDecoder::bitOffset() const { return m_bitsOffset; }

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
