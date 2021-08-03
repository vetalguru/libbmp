#include <iostream>
#include <string>

#include "bmp_decoder.hpp"
#include "foo.hpp"

int main() {
  std::cout << "Answer: " << return_42() << std::endl;

  const std::string file_name;
  Decoder::BmpDecoder bmp(file_name);

  return 0;
}
