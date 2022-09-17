#include <gtest/gtest.h>

#include "lib.hpp"

TEST(Test, Basic)
{
  auto const lib = library {};
  EXPECT_EQ(lib.name, "sts");
}
