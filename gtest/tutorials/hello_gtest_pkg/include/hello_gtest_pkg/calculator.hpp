#ifndef HELLO_GTEST_PKG_CALCULATOR_HPP_
#define HELLO_GTEST_PKG_CALCULATOR_HPP_

class Calculator
{
public:
  int add(int a, int b) const;
  int subtract(int a, int b) const;
  int multiply(int a, int b) const;
  int divide(int a, int b) const;
};

#endif
