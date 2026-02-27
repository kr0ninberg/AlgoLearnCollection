#include <gtest/gtest.h>
#include <string>

// Example test case
TEST(Basic, SampleTest) {
  EXPECT_EQ(1 + 1, 2);
  EXPECT_TRUE(true);
  EXPECT_FALSE(false);
}

// Another example test
TEST(Basic, Addition) {
  EXPECT_EQ(2 + 3, 5);
  EXPECT_NE(2 + 3, 6);
}

TEST(Basic, BasicOperations) {
  std::string str = "Hello";
  EXPECT_EQ(str.length(), 5);
  EXPECT_EQ(str + " World", "Hello World");
}