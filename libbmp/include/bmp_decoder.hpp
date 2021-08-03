#ifndef LIBBMP_INCLUDE_BMP_DECODER_HPP_
#define LIBBMP_INCLUDE_BMP_DECODER_HPP_

#include <string>

namespace Decoder {

struct BITMAP_FILE_HEADER;

class BmpDecoder {
public:
  explicit BmpDecoder(const std::string &aFileName);
  ~BmpDecoder();

  bool isValid() const;

  uint32_t fileSizeFromHeader() const;
  uint32_t bitOffset() const;

private:
  bool parseFile(const std::string &aFileName);

  bool decodeBitmapFileHeader(std::ifstream &aStream,
                              BITMAP_FILE_HEADER &aFileHeader);

private:
  bool m_isValid;

  uint32_t m_fileSize;
  uint32_t m_bitsOffset;
};

} // namespace Decoder

#endif // LIBBMP_INCLUDE_BMP_DECODER_HPP_
