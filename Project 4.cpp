// Project 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

void calcAry(double array[], int size, double& sum, double& average, double& highValue, double& lowValue);
void sortAry(double array[], int size);

int main()
{
    double array[100], sum, average, highValue, lowValue = 0.0;

    // Populate the array with random values
    for (int index = 0; index < 100; index++)
    {
        array[index] = (rand() % 300) * 1.1234;
    }

    calcAry(array, 100, sum, average, highValue, lowValue); // Calulate the array value
    sortAry(array, 100); //Sort the array

    // Display the results
    cout << setw(17) << "" << "Array manipulation program" << "\n\n\n";
    cout << "Total array value: " << setw(10) << fixed << setprecision(2) << sum << endl;
    cout << "Average array value: " << fixed << setprecision(2) << average << endl;
    cout << "Highest array value: " << fixed << setprecision(2) << highValue << endl;
    cout << "Lowest array value: " << setw(5) << fixed << setprecision(2) << lowValue << endl << endl;

    // Display the sorted array
    cout << "Sorted array values lowest to highest:" << endl;
    for (int index = 0; index < 10; index++)
    {
        cout << "Row " << index << ": ";

        for (int swapIndex = 0; swapIndex < 10; swapIndex++)
        {
            cout << setw(10) << fixed << setprecision(2) << array[10 * index + swapIndex];
        }
        cout << endl;
    }
    return 0;
}

void calcAry(double array[], int size, double& sum, double& average, double& highValue, double& lowValue)
{
    sum = 0.0;
    average = 0.0;
    highValue = array[0];
    lowValue = array[0];

    for (int index = 0; index < size; index++)
    {
        sum += array[index];

        if (array[index] > highValue)
        {
            highValue = array[index];
        }

        if (array[index] < lowValue)
        {
            lowValue = array[index];
        }
    }

    average = sum / size;
}

void sortAry(double array[], int size)
{
    for (int index = 0; index < size - 1; index++)
    {
        for (int swapIndex = 0; swapIndex < size - index - 1; swapIndex++)
        {
            if (array[swapIndex] > array[swapIndex + 1])
            {
                double temp = array[swapIndex];
                array[swapIndex] = array[swapIndex + 1];
                array[swapIndex + 1] = temp;
            }
        }
    }
}