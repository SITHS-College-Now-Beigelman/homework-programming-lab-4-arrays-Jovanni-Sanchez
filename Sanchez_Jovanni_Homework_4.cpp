// Jovanni Sanchez
// Homework 4
// 11/12/2024

#include <cmath>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

/* Part 1 */
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

/* Part 2 */
void findGreatestSalesperson(int list[], int listSize)
{
    int bestSalesperson = 0;
    int carsSoldByTheBest = 0;
    
    /*  */

    for (int currentPerson = 0; currentPerson < listSize; currentPerson++)
    {
        if (list[bestSalesperson] < list[currentPerson])
        {
            bestSalesperson = currentPerson;
            carsSoldByTheBest = list[bestSalesperson];
        }
    }

    cout << "\nSalesperson " << bestSalesperson + 1 << " sold the most cars with "
         << carsSoldByTheBest << " cars.";
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

    cout << "The total number of cars sold is "
         << totalNumberOfSoldCars << " cars.";
    findGreatestSalesperson(cars, 10);
}

/* Part 3 */
string validateDNA(string strandOfDNA)
{
    string tempStrand = "";

    /* The purpose of this function is to catch invalid characters and remove them
    while  */

    for (int currentChar = 0; currentChar < strandOfDNA.size(); currentChar++)
    {
        switch (strandOfDNA[currentChar])
        {
        case 'A':
            tempStrand += strandOfDNA[currentChar];
            break;
        case 'C':
            tempStrand += strandOfDNA[currentChar];
            break;
        case 'G':
            tempStrand += strandOfDNA[currentChar];
            break;
        case 'T':
            tempStrand += strandOfDNA[currentChar];
            break;
        default:
            tempStrand += "";
            break;
        }
    }

    return tempStrand;
}

void DNA_to_MRNA(string strandOfDNA)
{
    string tempStrand = "";

    for (int currentChar = 0; currentChar < strandOfDNA.size(); currentChar++)
    {
        switch (strandOfDNA[currentChar])
        {
        case 'A':
            tempStrand += "U";
            break;
        case 'C':
            tempStrand += "G";
            break;
        case 'G':
            tempStrand += "C";
            break;
        case 'T':
            tempStrand += "A";
            break;
        default:
            tempStrand += "";
            break;
        }
    }

    cout << tempStrand;
}

void partThree()
{
    string strandOfDNA;

    cout << "Please type your strand of DNA: ";
    cin.ignore(); // pausing here works for some reason???
    getline(cin, strandOfDNA);

    DNA_to_MRNA(validateDNA(strandOfDNA));
}

/* Part selector */
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

/* Main */
int main()
{
    int selectedPart;

    cout << "Please enter which part you want to test (1, 2, or 3): ";
    cin >> selectedPart;

    startDesiredPart(validateUserSelection(selectedPart));

    return 0;
}