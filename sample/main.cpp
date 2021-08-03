#include <iostream>
#include <string>

#include "bmp_decoder.hpp"
#include "foo.hpp"

int main() {
  std::cout << "Answer: " << return_42() << std::endl;

  const std::string file_name{};
  Decoder::BmpDecoder bmp(file_name);

  if (bmp.isValid()) {
    std::cout << "\nFile header" << std::endl;
    std::cout << "File size : " << bmp.fileSizeFromHeader() << std::endl;
    std::cout << "Bit offset : " << bmp.bitOffset() << std::endl;

    std::cout << "\nInfo header" << std::endl;
    std::cout << "Info structure size : " << bmp.infoStructureSize()
              << std::endl;
    std::cout << "Width : " << bmp.width() << std::endl;
    std::cout << "Height : " << bmp.height() << std::endl;
    std::cout << "Bit count : " << bmp.bitCount() << std::endl;
  }

  return 0;
}
