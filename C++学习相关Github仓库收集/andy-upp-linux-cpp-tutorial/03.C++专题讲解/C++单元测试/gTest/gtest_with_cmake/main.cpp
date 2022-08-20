#include <iostream>
#include <gtest/gtest.h>
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
// case1
TEST(test, c1) {
    EXPECT_EQ(3, add(1, 2));
    EXPECT_EQ(12, add(2, 6));
}
// case2
TEST(test, c2) {
    EXPECT_EQ(-1, sub(1, 2));
}
GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
