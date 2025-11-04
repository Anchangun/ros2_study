#include <gtest/gtest.h>
#include "hello_gtest_pkg/calculator.hpp"

TEST(CalculatorTest, AddPositiveNumbers) {
  Calculator calc;
  EXPECT_EQ(calc.add(2, 3), 5);
}

TEST(CalculatorTest, SubtractNumbers) {
  Calculator calc;
  EXPECT_EQ(calc.subtract(10, 4), 6);
}

TEST(CalculatorTest, MultiplyNumbers) {
  Calculator calc;
  EXPECT_EQ(calc.multiply(3, 4), 12);
}

//실패 테스트 (의도적)
TEST(CalculatorTest, WrongAddition) {
  Calculator calc;
  EXPECT_EQ(calc.add(2, 2), 5) << "이건 실패해야 하는 테스트입니다.";
}

TEST(CalculatorTest, DivisionByZeroThrows) {
  Calculator calc;
  EXPECT_THROW(calc.divide(10, 0), std::invalid_argument);
}
