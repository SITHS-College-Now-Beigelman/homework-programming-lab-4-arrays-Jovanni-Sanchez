// Jovanni Sanchez
// Homework 4
// 11/12/2024

#include <string>
#include <iostream>
using namespace std;

/* This function will filter through a list to find all the even numbers.
You are require to input a list and the size of the list. After, the function
will iterate through the items of the list, start a message, print out all the
even numbers seperated with a comma, then finally end with a period. The final
message should look like this "The even numbers in your array are:  x, y, z." */
void filterForEvens(int list[], int sizeOfList)
{
    int evenNumbers = 0;
    string ending = ", ";                           // Allows for changes later
    cout << "The even numbers in your array are: "; // Print before doing anything

    for (int currentItem = 0; currentItem != sizeOfList; currentItem++)
    {
        if ((currentItem == sizeOfList - 1) && (evenNumbers > 0))
        {
            ending = ".";
        }

        if (list[currentItem] % 2 == 0)
        {
            // Print the currentItem from the list, followed by a comma
            cout << list[currentItem] << ending;
            evenNumbers++;
        }
    }

    if (evenNumbers == 0)
    {
        cout << "none.";
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

/* This function will filter through a list to find the greatest Salesperson.
A variable for the best Salesperson and how many cars they have sold are setup
before filitering through the list. By default, the best salesperson is the 1st
salesperson. The filter works by seeing if the cars sold by best salesperson is
less than the current salesperson. If it is, then the current salesperson becomes
the new best salesperson and the amount of cars they have sold is stored. Once the
function is finished iterating through the list, it will print out who the best
salesperson is and how many cars they have sold. */
void findGreatestSalesperson(int list[], int listSize)
{
    int bestSalesperson = 0;   // Stores the best salesperson
    int carsSoldByTheBest = 0; // Stores the amonut of cars sold by the best

    for (int currentSalesperson = 0;
         currentSalesperson < listSize;
         currentSalesperson++)
    {
        if (list[bestSalesperson] < list[currentSalesperson])
        {
            bestSalesperson = currentSalesperson;
            carsSoldByTheBest = list[bestSalesperson];
        }
    }

    // Prints the best salesperson + the number of cars they sold
    cout << "\nSalesperson " << bestSalesperson + 1 << " sold the most cars with "
         << carsSoldByTheBest << " cars.";
}

/* Contains all the code for part 2. For every salesperson in the cars list,
their number and the amount of cars they have sold is printed. Alongside printing
the salespeople, the loop also adds up the total amount of cars sold at this
dealership before transitioning to the findGreatestSalesperson function to find
and print out the best salesperson in the dealership. */
void partTwo()
{
    int totalNumberOfSoldCars = 0;
    int cars[10] = {7, 3, 6, 0, 14, 8, 1, 2, 9, 8};

    for (int currentSalesperson = 0;
         currentSalesperson != 10;
         currentSalesperson++)
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
in a clean string of mRNA while the invalid characters are caught and deleted. */
string DNA_to_mRNA(string strandOfDNA)
{
    string strandOfmRNA = ""; // Setup a strand of MRNA

    /* The switch statement is used to identify valid characters. If the current
    character within the strandOfDNA is 'A', 'C', 'G', or 'T', then it will be
    converted to its corresponding mRNA character: 'U', 'G', 'C', or 'A'. For
    every other character in the strandOfDNA, nothing is added to the
    strandOfmRNA. */

    for (int currentChar = 0; currentChar != strandOfDNA.size(); currentChar++)
    {
        switch (strandOfDNA[currentChar])
        {
        case 'A':
            strandOfmRNA += "U";
            break;
        case 'C':
            strandOfmRNA += "G";
            break;
        case 'G':
            strandOfmRNA += "C";
            break;
        case 'T':
            strandOfmRNA += "A";
            break;
        default:
            strandOfmRNA += "";
            break;
        }
    }

    return strandOfmRNA; // Return the strand of MRNA
}

/* Contains all the code need for part 3 of the Homework. A strandOfDNA is setup,
the user enters their DNA strand, its cleaned up to take out invalid characters,
then convert to a MRNA strand. */
void partThree()
{
    string strandOfDNA; // Stores a strand of DNA for later

    cout << "Please type your strand of DNA: ";
    cin.ignore();              // pausing here works for some reason???
    getline(cin, strandOfDNA); /* Get the user's COMPLETE strand of DNA, with
    spaces and everything. Only works after ingnoring cin for some reason. */

    /* After getting the user's strandOfDNA, it's then inputted into the functions
    "validateDNA" and "DNA_to_MRNA". The results of both functions are printed
    out in a neat sentence to show the user their clean DNA strand and their
    MRNA strand. */

    cout << "Your DNA strand, " << validateDNA(strandOfDNA)
         << ", converted to MRNA is " << DNA_to_mRNA(validateDNA(strandOfDNA))
         << ".";
}

/* MAIN */
int main()
{
    cout << "\n";
    partOne();
    cout << "\n\n";
    partTwo();
    cout << "\n\n";
    partThree();
    cout << "\n\n";
    return 0;
}