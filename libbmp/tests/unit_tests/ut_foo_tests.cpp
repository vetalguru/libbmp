#include <gtest/gtest.h>

#include "foo.hpp"

TEST(Foo, return_42_SUCCESS) { EXPECT_EQ(return_42(), 42); }

TEST(Foo, return_42_FAIL) { EXPECT_NE(return_42(), 0); }
