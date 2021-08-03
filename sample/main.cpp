#include <iostream>
#include <string>

#include "bmp_decoder.hpp"
#include "foo.hpp"

int main() {
  std::cout << "Answer: " << return_42() << std::endl;

  const std::string file_name{"bmp_2x2_24bit.bmp"};
  Decoder::BmpDecoder bmp(file_name);

  if (bmp.isValid()) {
    std::cout << "File size : " << bmp.fileSizeFromHeader() << std::endl;
    std::cout << "Bit offset :" << bmp.bitOffset() << std::endl;
  }

  return 0;
}
