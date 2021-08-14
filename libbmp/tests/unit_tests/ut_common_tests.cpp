#include <gtest/gtest.h>

#include "common.hpp"

TEST(UtCommonTests, SwapBytes16_Ok) {
  uint16_t start = 0b0000000000000001;
  uint16_t expected = 0b0000000100000000;

  uint16_t result = swapBytes_16(start);
  EXPECT_EQ(expected, result);
}

TEST(UtCommonTests, SwapBytes32_OK) {
  uint32_t start = 0b00000000000000000000000000000001;
  uint32_t expected = 0b00000001000000000000000000000000;

  uint32_t result = swapBytes_32(start);
  EXPECT_EQ(expected, result);
}
