// Jovanni Sanchez
// Homework 4
// 11/12/2024

#include <cmath>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

/* This function will filter through a list to find all the even numbers.
You are require to input a list and the size of the list. After, the function
will iterate through the items of the list, start a message, print out all the
even numbers seperated with a comma, then finally end with a period. The final
message should look like this "The even numbers in your array are:  x, y, z." */
void filterForEvens(int list[], int sizeOfList)
{
    int currentItem = 0;
    string ending = ", ";                           // Allows for changes later
    cout << "The even numbers in your array are: "; // Print before doing anything

    for (int currentItem = 0; currentItem != sizeOfList; currentItem++)
    {

        if ((list[currentItem] % 2 == 0))
        {
            // Print the currentItem from the list, followed by a comma
            cout << list[currentItem] << ending;
        }

        if ((currentItem == sizeOfList - 1))
        {
            ending = ".";
        }
    }
}

/*
This function will take a number and return it as a string to display
ordinal numbers. Ordinal numbers, such as ‘first’, ‘second’ and ‘third’, show the
order, position or importance of things in a list or sequence. Ordinals written
as numerals always have a suffix:
• ‘-st’ (‘first’, ‘21st’)
• ‘-nd’ (‘second’, ‘32nd’)
• ‘-rd’ (‘third’, ‘103rd’)
• ‘-th’ (‘fourth’, ‘15th’, ‘55th’ and so on).
*/
string ordinalNumbers(int originalNumber)
{
    string numberWithSuffix = ""; // Setup a string for the number + suffix

    /* A switch statement is used for clarity and ease of use. If new entries for
    ordinal numbers such as 21st, 32nd, or 103rd are needed, they can easily be
    added as exeption cases.  */

    switch (originalNumber + 1) // Makes more sense to humans
    {
    case 1:
        numberWithSuffix = "1st";
        break;
    case 2:
        numberWithSuffix = "2nd";
        break;
    case 3:
        numberWithSuffix = "3rd";
        break;
    default:
        // to_string turns integers to strings
        numberWithSuffix = to_string(originalNumber + 1) + "th";
        break;
    }

    return numberWithSuffix; // return the number with its suffix
}

/* Contains all the code need for part 1 of the Homework. myArray is setup with
8 slots avaliable, the user enters 8 numbers, the list is inputed into a function
to filter out the evens and print out a complete list of those evens. */
void partOne()
{
    int myArray[8];
    int currentItem;

    for (currentItem = 0; currentItem != 8; currentItem++)
    {
        int userValue;
        cout << "Please enter your " << ordinalNumbers(currentItem)
             << " number: ";
        cin >> userValue;

        myArray[currentItem] = userValue;
    }

    filterForEvens(myArray, 8);
    cout << "\n";
}

/* PART 2 - TOTAL # OF CARS + BEST SALESPERSON IN DEALERSHIP */
void findGreatestSalesperson(int list[], int listSize)
{
    int bestSalesperson = 0;
    int carsSoldByTheBest = 0;

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
    cout << endl;
}

/* The purpose of this function is to clean up DNA strands. The function will
iterate through each character in the strandOfDNA until it reaches the end of the
strand. Only valid characters will be returned in a clean string while the invalid
characters are caught and deleted. */
string validateDNA(string strandOfDNA)
{
    string cleanStrand = ""; // Setup a clean strand of DNA

    /* The switch statement is used to identify valid characters. If the
    strandOfDNA has 'A', 'C', 'G', or 'T', then they will be add to the clean
    strand. For every other character in the strandOfDNA, nothing is added to
    the cleanStrand. */

    for (int currentChar = 0; currentChar != strandOfDNA.size(); currentChar++)
    {
        switch (strandOfDNA[currentChar])
        {
        case 'A':
            cleanStrand += strandOfDNA[currentChar];
            break;
        case 'C':
            cleanStrand += strandOfDNA[currentChar];
            break;
        case 'G':
            cleanStrand += strandOfDNA[currentChar];
            break;
        case 'T':
            cleanStrand += strandOfDNA[currentChar];
            break;
        default:
            cleanStrand += "";
            break;
        }
    }

    return cleanStrand; // Return the newly cleaned DNA strand
}

/* The purpose of this function is to convert DNA strands to MRNA strands.
The function will identify valid DNA characters and convert them to equivalent
MRNA characters. The function will iterate through each character in the strand of
DNA until it reaches the end of the strand. Only valid characters will be returned
in a clean string of MRNA while the invalid characters are caught and deleted. */
string DNA_to_MRNA(string strandOfDNA)
{
    string strandOfMRNA = ""; // Setup a strand of MRNA

    /* The switch statement is used to identify valid characters. If the current
    character within the strandOfDNA is 'A', 'C', 'G', or 'T', then it will be
    converted to its corresponding MRNA character: 'U', 'G', 'C', or 'A'. For
    every other character in the strandOfDNA, nothing is added to the
    strandOfMRNA. */

    for (int currentChar = 0; currentChar != strandOfDNA.size(); currentChar++)
    {
        switch (strandOfDNA[currentChar])
        {
        case 'A':
            strandOfMRNA += "U";
            break;
        case 'C':
            strandOfMRNA += "G";
            break;
        case 'G':
            strandOfMRNA += "C";
            break;
        case 'T':
            strandOfMRNA += "A";
            break;
        default:
            strandOfMRNA += "";
            break;
        }
    }

    return strandOfMRNA; // Return the strand of MRNA
}

/* Contains all the code need for part 3 of the Homework. A strandOfDNA is setup,
the user enters their DNA strand, its cleaned up to take out invalid characters,
then convert to a MRNA strand. */
void partThree()
{
    string strandOfDNA; // Stores a strand of DNA for later

    cout << "Please type your strand of DNA: ";
    cin.ignore();              // pausing here works for some reason???
    getline(cin, strandOfDNA); // Get the user's COMPLETE strand of DNA, with
    // spaces and everything. Only works after ingnoring cin for some reason.

    /* After getting the user's strandOfDNA, it's then inputted into the functions
    "validateDNA" and "DNA_to_MRNA". The results of both functions are printed
    out in a neat sentence to show the user their clean DNA strand and their
    MRNA strand. */

    cout << "Your DNA strand, " << validateDNA(strandOfDNA)
         << ", converted to MRNA is " << DNA_to_MRNA(validateDNA(strandOfDNA))
         << ".";
}

/* MAIN */
int main()
{
    partOne();
    partTwo();
    partThree();
    return 0;
}