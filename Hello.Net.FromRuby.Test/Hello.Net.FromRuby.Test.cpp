#include "stdafx.h"
#include <Person.h>
#include "MemoryLeakDetector.h"

TEST(Person, ItCleansUpMemory) {
  auto person = Person(true, 123, "The name", "English");
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  UnitTest::GetInstance()->listeners().Append(new MemoryLeakDetector());
  return RUN_ALL_TESTS();
}

