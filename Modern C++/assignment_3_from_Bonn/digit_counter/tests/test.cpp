#include<gtest/gtest.h>
#include<cmath>
#include "digit_counter/digit_counting.h"

TEST(TestDigit, Wrap){
    EXPECT_EQ(100, digit::Warp(100,2));
}


TEST(TestDigit, Warp) {
  double pi = 3.14159265;
  double factor = 1e17;

  double pi_warped = digit::Warp(pi, factor);
  EXPECT_FALSE(std::fabs(pi - pi_warped) < 1e-2);
}

TEST(TestDigit, SignificantDifferent) {
  double a = 0.34567823;
  double b = 0.34568888;

  EXPECT_EQ(digit::CountSameSignificantDigits(a, b), 4);
}

TEST(TestDigit, SignificantBothGreater) {
  double a = 1.34567823;
  double b = 2.34568888;

  EXPECT_EQ(digit::CountSameSignificantDigits(a, b), -1);
}
