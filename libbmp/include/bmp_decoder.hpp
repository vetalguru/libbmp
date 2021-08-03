#ifndef LIBBMP_INCLUDE_BMP_DECODER_HPP_
#define LIBBMP_INCLUDE_BMP_DECODER_HPP_

#include <string>

namespace Decoder {

struct BITMAP_FILE_HEADER;
struct BITMAP_INFO_HEADER;

class BmpDecoder {
public:
  explicit BmpDecoder(const std::string &aFileName);
  ~BmpDecoder();

  bool isValid() const;

  uint32_t fileSizeFromHeader() const;
  uint32_t bitOffset() const;

  uint32_t infoStructureSize() const;
  int32_t width() const;
  int32_t height() const;
  uint16_t bitCount() const;

private:
  bool parseFile(const std::string &aFileName);

  bool decodeBitmapFileHeader(std::ifstream &aStream,
                              BITMAP_FILE_HEADER &aFileHeader);
  bool decodeBitmapInfoHeader(std::ifstream &aStream,
                              BITMAP_INFO_HEADER &aFileHeader);

private:
  bool m_isValid;

  uint32_t m_fileSize;
  uint32_t m_bitsOffset;

  uint32_t m_infoStructSize;
  uint16_t m_bitCount;

  int32_t m_width;
  int32_t m_height;
};

} // namespace Decoder

#endif // LIBBMP_INCLUDE_BMP_DECODER_HPP_
