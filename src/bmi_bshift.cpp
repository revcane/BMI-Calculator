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

// calculates bmi using: (weight/ height^2) * 703
double calculateBMI(double weightLbs, double heightInches)
{
    if (weightLbs <= 0)
    {
        throw std::invalid_argument("Weight must be positive.");
    }
    if (heightInches <= 0)
    {
        throw std::invalid_argument("Height must be positive.");
    }
    double bmi = (weightLbs / (heightInches * heightInches)) * 703;
    return std::round(bmi * 10) / 10; // round to 1 decimal place
}

// returns BMI category based on standard BMI ranges
// ------------------------------
//   underweight: BMI < 18.5
//   normal: 18.5 <= BMI <= 24.9
//   overweight: 25.0 <= BMI <= 29.9
//   obese: BMI >= 30.0
// ------------------------------
std::string getBMICategory(double bmi)
{
    if (bmi < 18.6) // added boundary shift error
    {
        return "Underweight";
    }
    else if (bmi <= 24.9)
    {
        return "Normal weight";
    }
    else if (bmi <= 29.9)
    {
        return "Overweight";
    }
    else
    {
        return "Obese";
    }
}

// using both helper functions, compute BMI using feet, inches, and weight, return bmi value
double computeBMI(int feet, double inches, double weightLbs)
{
    double totalInches = heightToInches(feet, inches);
    return calculateBMI(weightLbs, totalInches);
}
