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

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
