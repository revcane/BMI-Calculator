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

// getBMICategory tests
// ------------------------------
//   underweight: BMI < 18.5
//   normal: 18.5 <= BMI <= 24.9
//   overweight: 25.0 <= BMI <= 29.9
//   obese: BMI >= 30.0
// ------------------------------

// tests BMI of 10.0 returns Underweight
TEST(GetBMICategoryTest, lowright)
{
    EXPECT_EQ(getBMICategory(10.0), "Underweight");
}

// tests BMI of 18.4 (slightly below normal boundary) should return underweight
TEST(GetBMICategoryTest, belownormal)
{
    EXPECT_EQ(getBMICategory(18.4), "Underweight");
}

// tests BMI of 18.5 (lower boundary of normal) should return normal
TEST(GetBMICategoryTest, normallower)
{
    EXPECT_EQ(getBMICategory(18.5), "Normal weight");
}

// tests BMI of 18.6 (slightly above normal lower boundary) should return normal
TEST(GetBMICategoryTest, abovenormallower)
{
    EXPECT_EQ(getBMICategory(18.6), "Normal weight");
}

// tests BMI of 22.0 (mid normal range) should return normal
TEST(GetBMICategoryTest, midnormal)
{
    EXPECT_EQ(getBMICategory(22.0), "Normal weight");
}

// tests BMI of 24.9 (upper boundary of normal) should return normal
TEST(GetBMICategoryTest, normalupper)
{
    EXPECT_EQ(getBMICategory(24.9), "Normal weight");
}

// tests BMI of 25.0 (lower boundary of overweight) should return overweight
TEST(GetBMICategoryTest, overweightlower)
{
    EXPECT_EQ(getBMICategory(25.0), "Overweight");
}

// tests BMI of 25.1 (slightly above overweight lower boundary) should return overweight
TEST(GetBMICategoryTest, aboveoverweightlower)
{
    EXPECT_EQ(getBMICategory(25.1), "Overweight");
}

// tests BMI of 27.5 (mid overweight range) should return overweight
TEST(GetBMICategoryTest, midoverweight)
{
    EXPECT_EQ(getBMICategory(27.5), "Overweight");
}

// tests BMI of 29.9 (upper boundary of overweight) should return overweight
TEST(GetBMICategoryTest, overweightupper)
{
    EXPECT_EQ(getBMICategory(29.9), "Overweight");
}

// tests BMI of 30.0 (lower boundary of obese) should return obese
TEST(GetBMICategoryTest, obeselower)
{
    EXPECT_EQ(getBMICategory(30.0), "Obese");
}

// tests BMI of 30.1 (slightly above obese lower boundary) should return obese
TEST(GetBMICategoryTest, aboveobeselower)
{
    EXPECT_EQ(getBMICategory(30.1), "Obese");
}

// tests BMI of 40.0 (high obese range) should return obese
TEST(GetBMICategoryTest, highobese)
{
    EXPECT_EQ(getBMICategory(40.0), "Obese");
}

// computeBMI tests

// tests 5'9" 100 lbs should return underweight
TEST(ComputeBMITest, underweight)
{
    double bmi = computeBMI(5, 9.0, 100.0);
    EXPECT_EQ(getBMICategory(bmi), "Underweight");
}

// tests 5'9" 155 lbs should return normal weight
TEST(ComputeBMITest, normalweight)
{
    double bmi = computeBMI(5, 9.0, 155.0);
    EXPECT_EQ(getBMICategory(bmi), "Normal weight");
}

// tests 5'6" 180 lbs should return overweight
TEST(ComputeBMITest, overweight)
{
    double bmi = computeBMI(5, 6.0, 180.0);
    EXPECT_EQ(getBMICategory(bmi), "Overweight");
}

// tests 5'6" 220 lbs should return obese
TEST(ComputeBMITest, obese)
{
    double bmi = computeBMI(5, 6.0, 220.0);
    EXPECT_EQ(getBMICategory(bmi), "Obese");
}

// expected to throw invalid argument error for negative feet
TEST(ComputeBMITest, negativefeet)
{
    EXPECT_THROW(computeBMI(-1, 0.0, 150.0), std::invalid_argument);
}

// expected to throw invalid argument error for zero weight
TEST(ComputeBMITest, zeroweight)
{
    EXPECT_THROW(computeBMI(5, 10.0, 0.0), std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
