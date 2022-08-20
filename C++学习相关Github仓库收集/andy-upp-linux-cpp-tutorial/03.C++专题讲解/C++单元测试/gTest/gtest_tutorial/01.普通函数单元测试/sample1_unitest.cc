// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
// 这个例子展示了如何使用C++ 单元测试框架对函数进行单元测试
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:
// 利用Google C++单元测试框架做单元测试只须简单的三步
// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// 第一步，包含必要的头部文件，确保测试逻辑所需要的头文件已被声明，并且不要忘记
// gtest.h。
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "sample1.h"
#include "gtest/gtest.h"
// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
//第二步，TEST宏有两个参数，分别为测试用例集名称和测试用例名称，在使用这个宏以后，
//你需要在{}内定义你的测试逻辑。你可以使用一系列的宏来表示测试的成功或着失败。例如
//EXPECT_TRUE表示期望值正确，EXPECT_EQ表示结果值大于或等于期望值。
//
//
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
//技术细节：
//    在Google Test中，测试用例被分成测试用例集，这保证了我们的代码有良好的组织性，所以
//你应该把逻辑相关的测试用例归集到同一测试用例集当中。
//
//测试用例集名称以及测试用例名称必须是C++合法的标识符，并且在名称中不允许使用下划线（_）
//Google Test测试框架，可以保证所有定义的测试都能够被正确执行，但是对测试执行的顺序比如先执行那些
//后执行那些并没有保证。所以你编写的测试代码，其测试结果不应该依赖于其执行顺序。
//
// </TechnicalDetails>
// Tests Factorial().
// Tests factorial of negative numbers.
// 测试负数的阶乘

TEST(FactorialTest, Negative) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // 测试用例集的名称是 FactorialTest, 测试用例名称 是 Negative
  // test case.
  EXPECT_EQ(1, Factorial(-5));
  EXPECT_EQ(1, Factorial(-1));
  EXPECT_GT(Factorial(-10), 0);
// <TechnicalDetails>
  //
  // EXPECT_EQ(expected, actual) is the same as
  //
  //   EXPECT_TRUE((expected) == (actual))
  //
  // except that it will print both the expected value and the actual
  // value when the assertion fails.  This is very helpful for
  // debugging.  Therefore in this case EXPECT_EQ is preferred.
  //
  // On the other hand, EXPECT_TRUE accepts any Boolean expression,
  // and is thus more general.
  //
  //技术细节：
  //    EXPECT_EQ(expected,actual)与EXPECT_TRUE((expected)==(actual))是等同的，有一点
  //不同的是，当EXPECT_EQ(expected,actual)失败时会打印出期望的值与实际的值，这对调试非常有帮助，因此使用EXPECT_EQ更好一些。
  //
  //但是从另一方面说，由于EXPECT_TRUE可以接受任何类型的布尔表达式，所以应用更广一些
  //
  // </TechnicalDetails>
}

// Tests factorial of 0.
TEST(FactorialTest, Zero) {
  EXPECT_EQ(1, Factorial(0));
}
// Tests factorial of positive numbers.
TEST(FactorialTest, Positive) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(40320, Factorial(8));
}
// Tests IsPrime()
// Tests negative input.
TEST(IsPrimeTest, Negative) {
  // This test belongs to the IsPrimeTest test case.
EXPECT_FALSE(IsPrime(-1));
  EXPECT_FALSE(IsPrime(-2));
  EXPECT_FALSE(IsPrime(INT_MIN));
}
// Tests some trivial cases.
TEST(IsPrimeTest, Trivial) {
  EXPECT_FALSE(IsPrime(0));
  EXPECT_FALSE(IsPrime(1));
  EXPECT_TRUE(IsPrime(2));
  EXPECT_TRUE(IsPrime(3));
}
// Tests positive input.
TEST(IsPrimeTest, Positive) {
  EXPECT_FALSE(IsPrime(4));
  EXPECT_TRUE(IsPrime(5));
  EXPECT_FALSE(IsPrime(6));
  EXPECT_TRUE(IsPrime(23));
}
// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?
//
// 第三步，我们在编译的时候会链接src/gtest_main.cc 文件，这个文件包含了
// main()函数，在main()函数里调用RUN_ALL_TESTS(), 而此函数会调用我们所定义
// 的所有TEST（）函数，并打印运行结果，返回值为0表示成功，为1表示失败。
//
// 由于我们不许要注册这些测试，RUN_ALL_TESTS()就全部替我们做好，所以此框架
// 使用起来非常的方便。
