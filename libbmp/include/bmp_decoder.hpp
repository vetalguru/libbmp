#ifndef LIBBMP_INCLUDE_BMP_DECODER_HPP_
#define LIBBMP_INCLUDE_BMP_DECODER_HPP_

#include <string>

namespace Decoder {

class BmpDecoder {
public:
  explicit BmpDecoder(const std::string &aFileName);

  ~BmpDecoder();
};

} // namespace Decoder

#endif // LIBBMP_INCLUDE_BMP_DECODER_HPP_
