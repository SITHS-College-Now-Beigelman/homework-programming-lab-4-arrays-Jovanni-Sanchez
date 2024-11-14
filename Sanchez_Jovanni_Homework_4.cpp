// Jovanni Sanchez
// Homework 4
// 11/12/2024

#include <cmath>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

void evenOrOdd(int list[], int sizeOfList)
{
    for (int currentItem = 0; currentItem < sizeOfList; currentItem++)
    {
        if (list[currentItem] % 2 == 0)
        {
            cout << list[currentItem] << " is an even number.\n";
        }
        else
        {
            cout << list[currentItem] << " is an odd number.\n";
        }
    }
}

void findGreatestSalesperson(int list[], int listSize)
{
    int bestSalesperson = 0;
    int carsSoldByTheBest = 0;

    for (int currentSalesperson = 0; currentSalesperson < listSize; currentSalesperson++)
    {
        if (list[bestSalesperson] < list[currentSalesperson])
        {
            bestSalesperson = currentSalesperson;
            carsSoldByTheBest = list[bestSalesperson];
        }
    }

    cout << "\nSalesperson " << bestSalesperson + 1 << " sold the most cars with "
         << carsSoldByTheBest << " cars.";
}

void partOne()
{
    int myArray[8];
    int currentItem;

    for (currentItem = 0; currentItem != 8; currentItem++)
    {
        int userValue;
        cout << "Please enter a number: ";
        cin >> userValue;

        myArray[currentItem] = userValue;
    }

    evenOrOdd(myArray, 8);
}

void partTwo()
{
    int currentSalesperson;
    int theBestSalespersonEver;
    int totalNumberOfSoldCars = 0;
    int cars[10] = {7, 3, 6, 0, 14, 8, 1, 2, 9, 8};

    for (currentSalesperson = 0; currentSalesperson != 10; currentSalesperson++)
    {
        totalNumberOfSoldCars = totalNumberOfSoldCars + cars[currentSalesperson];
        cout << "Salesperson " << currentSalesperson + 1 << " has sold "
             << cars[currentSalesperson] << " cars.\n";
    }

    cout << "The total number of cars sold is " << totalNumberOfSoldCars << " cars.";
    findGreatestSalesperson(cars, 10);
}

string validateDNA(string strandOfDNA)
{
    return strandOfDNA;
}

void split(string str, char del)
{
    // declaring temp string to store the curr "word" upto del
    string temp = "";

    for (int i = 0; i < str.size(); i++)
    {
        // If cur char is not del, then append it to the cur "word", otherwise
        // you have completed the word, print it, and start a new word.
        if (str[i] != del)
        {
            temp += str[i];
        }
        else
        {
            cout << temp << "";
            temp = "";
        }
    }

    cout << temp;
}

void partThree()
{
    string strandOfDNA;
    char del = '-';

    cout << "Please type your strand of DNA: ";
    cin >> strandOfDNA;

    cout << validateDNA(strandOfDNA);
}

int validateUserSelection(int userSelection)
{
    while (userSelection < 1 || userSelection > 3)
    {
        cout << "There are only 3 parts. "
             << "Please type either 1, 2, or 3 corresponding to "
             << "your part: ";
        cin >> userSelection;
    }
    return userSelection;
}

void startDesiredPart(int userSelection)
{
    switch (userSelection)
    {
    case 1:
        partOne();
        break;
    case 2:
        partTwo();
        break;
    case 3:
        partThree();
        break;
    default:
        break;
    }
}

int main()
{
    int selectedPart;

    cout << "Please enter which part you want to test (1, 2, or 3): ";
    cin >> selectedPart;

    selectedPart = validateUserSelection(selectedPart);

    startDesiredPart(selectedPart);

    return 0;
}