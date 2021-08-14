#ifndef LIBBMP_INCLUDE_BMP_DECODER_HPP_
#define LIBBMP_INCLUDE_BMP_DECODER_HPP_

#include <string>
#include <vector>

namespace Decoder {

struct BITMAP_FILE_HEADER;
struct BITMAP_INFO_HEADER;

class BmpDecoder {
public:
  struct PixelColor {
    uint8_t Red{0};
    uint8_t Green{0};
    uint8_t Blue{0};
    uint8_t Alpha{0};

    PixelColor() = default;
    PixelColor(uint8_t aRed, uint8_t aGreen, uint8_t aBlue, uint8_t aAlpha = 0)
        : Red{aRed}, Green{aGreen}, Blue{aBlue}, Alpha{aAlpha} {}
    ~PixelColor() = default;

    bool operator==(const PixelColor &other) const {
      return ((Red == other.Red) && (Green == other.Green) &&
              (Blue == other.Blue) && (Alpha == other.Alpha));
    }
  };

public:
  explicit BmpDecoder(const std::string &aFileName);
  ~BmpDecoder();

  bool isValid() const;

  uint32_t fileSizeFromHeader() const;
  uint32_t bitOffset() const;

  uint32_t infoStructureSize() const;
  uint32_t width() const;
  uint32_t height() const;
  uint16_t bitCount() const;

  bool pixelColor(const uint32_t aX, const uint32_t aY,
                  PixelColor &aPixelColor) const;

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

  std::vector<std::vector<PixelColor>> m_bitmap;
};

} // namespace Decoder

#endif // LIBBMP_INCLUDE_BMP_DECODER_HPP_
