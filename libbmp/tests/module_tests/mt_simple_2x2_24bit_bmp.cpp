#include <gtest/gtest.h>

#include <memory>

#include "bmp_decoder.hpp"

class Simple_2x2_24bit_bmp : public ::testing::Test {
protected:
  const std::string kTestFileName{"test_data/initial/bmp_2x2_24bit.bmp"};

  std::unique_ptr<Decoder::BmpDecoder> bmp_{
      std::make_unique<Decoder::BmpDecoder>(kTestFileName)};
};

TEST_F(Simple_2x2_24bit_bmp, ParseFile_Ok) {
  ASSERT_TRUE(bmp_);
  ASSERT_TRUE(bmp_->isValid());
}

TEST_F(Simple_2x2_24bit_bmp, FileSizeFromHeader_Ok) {
  ASSERT_TRUE(bmp_);
  EXPECT_EQ(138, bmp_->fileSizeFromHeader());
}

TEST_F(Simple_2x2_24bit_bmp, BitOffset_Ok) {
  ASSERT_TRUE(bmp_);
  EXPECT_EQ(122, bmp_->bitOffset());
}

TEST_F(Simple_2x2_24bit_bmp, InfoStructureSize_Ok) {
  ASSERT_TRUE(bmp_);
  EXPECT_EQ(108, bmp_->infoStructureSize());
}

TEST_F(Simple_2x2_24bit_bmp, Width_Ok) {
  ASSERT_TRUE(bmp_);
  EXPECT_EQ(2, bmp_->width());
}

TEST_F(Simple_2x2_24bit_bmp, Height_Ok) {
  ASSERT_TRUE(bmp_);
  EXPECT_EQ(2, bmp_->height());
}

TEST_F(Simple_2x2_24bit_bmp, BitCount_Ok) {
  ASSERT_TRUE(bmp_);
  EXPECT_EQ(24, bmp_->bitCount());
}

TEST_F(Simple_2x2_24bit_bmp, PixelColor_Ok) {
  ASSERT_TRUE(bmp_);

  // RED 0.0
  Decoder::BmpDecoder::PixelColor expected{255, 0, 0};
  Decoder::BmpDecoder::PixelColor result;
  EXPECT_TRUE(bmp_->pixelColor(0, 0, result));
  EXPECT_TRUE(expected == result);

  // GREEN 0.1
  expected = Decoder::BmpDecoder::PixelColor(0, 255, 0);
  EXPECT_TRUE(bmp_->pixelColor(0, 1, result));
  EXPECT_TRUE(expected == result);

  // BLUE 1.0
  expected = Decoder::BmpDecoder::PixelColor(0, 0, 255);
  EXPECT_TRUE(bmp_->pixelColor(1, 0, result));
  EXPECT_TRUE(expected == result);

  // WHITE 1.1
  expected = Decoder::BmpDecoder::PixelColor(255, 255, 255);
  EXPECT_TRUE(bmp_->pixelColor(1, 1, result));
  EXPECT_TRUE(expected == result);
}
