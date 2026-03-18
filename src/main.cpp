#include <iostream>
#include <iomanip>
#include <limits>
#include "bmi.h"
using namespace std;

int main()
{
    int feet;
    double inches, weight;

    cout << "   BMI Calculator  \n";
    cout << "====================\n\n";

    // ask user for height in feet and inches, then ask for weight, re-ask if invalid
    cout << "Enter height:\n";
    cout << "  Feet: ";
    while (!(cin >> feet) || feet < 0)
    {
        cout << "  Invalid input. Enter a non-negative integer for feet: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "  Inches: ";
    while (!(cin >> inches) || inches < 0)
    {
        cout << "  Invalid input. Enter a non-negative number for inches: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter weight (in pounds): ";
    while (!(cin >> weight) || weight <= 0)
    {
        cout << "  Invalid input. Enter a positive number for weight: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // compute BMI and display result and category
    try
    {
        double bmi = computeBMI(feet, inches, weight);
        string category = getBMICategory(bmi);

        cout << "\n------------------------------\n";
        cout << "  BMI:      " << fixed << setprecision(1) << bmi << "\n";
        cout << "  Category: " << category << "\n";
        cout << "------------------------------\n";
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;

    return 0;
}