// test_bmi.cpp
// using google test

#include <gtest/gtest.h>
#include <cmath>
#include "bmi.h"

// heightToInches tests

// tests 5 feet 0 inches converts to 60 total inches
TEST(HeightToInchesTest, fivefoot)
{
    EXPECT_DOUBLE_EQ(heightToInches(5, 0.0), 60.0);
}

// tests 5 feet 6 inches converts to 66 total inches
TEST(HeightToInchesTest, fivesix)
{
    EXPECT_DOUBLE_EQ(heightToInches(5, 6.0), 66.0);
}

// tests 6 feet 0 inches converts to 72 total inches
TEST(HeightToInchesTest, sixfoot)
{
    EXPECT_DOUBLE_EQ(heightToInches(6, 0.0), 72.0);
}

// tests 0 feet 0 inches converts to 0 total inches
TEST(HeightToInchesTest, zero)
{
    EXPECT_DOUBLE_EQ(heightToInches(0, 0.0), 0.0);
}

// expected to throw invalid argument error
TEST(HeightToInchesTest, negativefeet)
{
    EXPECT_THROW(heightToInches(-1, 0.0), std::invalid_argument);
}

// expected to throw invalid argument error
TEST(HeightToInchesTest, negativeinches)
{
    EXPECT_THROW(heightToInches(5, -1.0), std::invalid_argument);
}

// calculateBMI tests
// tests 150 lbs at 66 inches should return BMI of 24.2
TEST(CalculateBMITest, KnownValue150lbs66in)
{
    EXPECT_NEAR(calculateBMI(150.0, 66.0), 24.2, 0.05);
}

// tests that result is rounded to 1 decimal place
TEST(CalculateBMITest, ResultRoundedToOneDecimal)
{
    double result = calculateBMI(130.0, 64.0);
    double rounded = std::round(result * 10.0) / 10.0;
    EXPECT_NEAR(result, rounded, 0.0001);
}

// expected invalid argument error for zero weight
TEST(CalculateBMITest, ZeroWeightThrows)
{
    EXPECT_THROW(calculateBMI(0.0, 66.0), std::invalid_argument);
}

// expected invalid argument error for negative weight
TEST(CalculateBMITest, NegativeWeightThrows)
{
    EXPECT_THROW(calculateBMI(-10.0, 66.0), std::invalid_argument);
}

// expected invalid argument error for zero height
TEST(CalculateBMITest, ZeroHeightThrows)
{
    EXPECT_THROW(calculateBMI(150.0, 0.0), std::invalid_argument);
}

// expected invalid argument error for negative height
TEST(CalculateBMITest, NegativeHeightThrows)
{
    EXPECT_THROW(calculateBMI(150.0, -5.0), std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
