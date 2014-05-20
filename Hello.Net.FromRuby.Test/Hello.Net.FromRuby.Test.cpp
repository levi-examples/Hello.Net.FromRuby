#include "stdafx.h"

TEST(Hello, GoogleTest) {
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

