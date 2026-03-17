#ifndef BMI_H
#define BMI_H

#include <string>

double heightToInches(int feet, double inches);

double calculateBMI(double weightLbs, double heightInches);

std::string getBMICategory(double bmi);

double computeBMI(int feet, double inches, double weightLbs);

#endif // BMI_H