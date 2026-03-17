#include "bmi.h"
#include <stdexcept>
#include <cmath>

// converts height in feet and inches to total inches
double heightToInches(int feet, double inches)
{
    if (feet < 0 || inches < 0)
    {
        throw std::invalid_argument("Height values must be non-negative.");
    }
    return (feet * 12.0) + inches;
}

// just a stub for now
double calculateBMI(double weightLbs, double heightInches)
{
    return 0.0;
}

// just a stub for now
std::string getBMICategory(double bmi)
{
    return "";
}

// just a stub for now
double computeBMI(int feet, double inches, double weightLbs)
{
    return 0.0;
}
