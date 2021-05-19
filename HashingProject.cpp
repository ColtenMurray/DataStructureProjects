//   Roster Number : 40
//
//   Author : Colten Murray
//   Due Date : 12/03/18
//   Programming Assignment Number 8 - Optional
//
//   Fall 2018 - CS 3358 - 002
//
//   Instructor: Husain Gholoom
//
//   This program:
//   - Creates a hash table of size thirty and initializes all values as *.
//   - populates first 20 values with random integers between 88-525.
//   - Displays the generated table along with a menu of options to edit the
//     table.
//   - Displays number of linear probes when each number is hashed and collision
//     occured when adding an element in the table at the end of the program.

#include <iostream>
#include <stdlib.h>

using namespace std;

const int SIZE = 30;        // size of hash table

class hash
{
private:
    int intArr[SIZE];       // array representing the hash table
    int probes = 0;         // number of linear probes
public:
    void insert();          // inserts new value into hash table
    void search();          // searches for a value in the hash table
    void display();         // displays hash table
    void deleter();         // deletes a value in the hash table
    void populate();        // populates first 20 values w/ random values 88-525
    void empty();           // populates all values with *
    int getProbes();        // returns number of linear probes
};

void hash::insert()         // inserts new value into hash table
{
    int inp;                // user's input
    int loc;                // input storage location

    bool correct = false;   // determines if input is correct
    bool col = false;       // determines if there is collision

    cout << "\nEnter a number you want to insert (between 88-525): ";
    cin >> inp;
    while (!correct)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore('\n',INT_MAX);
            cout << "\nPlease Choose an int between 88-525\n";
            cin >> inp;
            cout << endl;
        }
        if(inp >= 88 && inp <= 525)
            correct = true;
        else
        {
            cout << "\nPlease Choose an int between 88-525\n";
            cin >> inp;
            cout << endl;
        }
    }

    loc = inp % SIZE;

        do
        {
            if(intArr[loc] == 0 )
            {
                intArr[loc] = inp;
                col = false;
            }
            else
            {
                probes += 1;
                loc = (inp + 1) % 100;
                col = true;
            }
        }
        while(col);

        cout << "\nThe number " << inp << " was added.\n" ;

}

void hash::search()                    // searches for a value in the hash table
{
    int inp;                           // user's input
    bool correct = false;              // determines if input is correct

    cout << "\nEnter a number you want to search (between 88-525): ";
    cin >> inp;
    while (!correct)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore('\n',INT_MAX);
            cout << "\nPlease Choose an int between 88-525\n";
            cin >> inp;
            cout << endl;
        }

        if(inp >= 88 && inp <= 525)
        {
            correct = true;
        }

        else
        {
            cout << "\nPlease Choose an int between 88-525\n";
            cin >> inp;
            cout << endl << endl;
        }
    }

    for(int i = 0; i < SIZE; i++)
    {
        if(intArr[i] == inp)
        {
            cout << "\nThe number " << inp << " was found in location " << i + 1
                 << endl;
            break;
        }
        else if(i == SIZE - 1)
        {
            cout << "\nThe number " << inp << " not found in the array"
                 << endl;
        }
    }
}

void hash::display()                      // displays hash table
{
    for(int i = 0; i < SIZE; i++)
    {
        if(i == 15)
            cout << endl;
        if(intArr[i] == 0)
            cout << "* ";
        else
            cout << intArr[i] << " ";
    }
}

void hash::deleter()                      // deletes a value in the hash table
{
    int inp;                              // users input
    bool correct = false;                 // determines if input is correct

    cout << "\nEnter a number you want to delete (between 88-525): ";
    cin >> inp;
    while (!correct)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore('\n',INT_MAX);
            cout << "\nPlease Choose an int between 88-525\n";
            cin >> inp;
            cout << endl;
        }
        if(inp >= 88 && inp <= 525)
            correct = true;
        else
        {
            cout << "\nPlease Choose an int between 88-525\n";
            cin >> inp;
            cout << endl;
        }
    }

    for(int i = 0; i < SIZE; i++)
    {
        if(intArr[i] == inp)
        {
            cout << endl << inp << " Has been deleted"
                 << endl;
            intArr[i] = 0;
            break;
        }
        else if(i == SIZE - 1)
        {
            cout << "\nThe number " << inp << " was not found"
                 << endl;
        }
    }
}

void hash::populate()       // populates first 20 values w/ random values 88-525
{
    int val;                // random value between 88 - 525
    int loc;                // value hash map location
    bool col = false;       // determines if there is collision

    for(int i = 0; i < 20; i++)
    {
        val = (rand() % (437 + 1)) + 88;
        loc = val % SIZE;
        do
        {
            if(intArr[loc] == 0 )
            {
                intArr[loc] = val;
                col = false;
            }
            else
            {
                probes += 1;
                val++;
                loc = val % SIZE;
                col = true;
            }
        }
        while(col);
    }
}

void hash::empty()          // populates all values with *
{
    for(int i = 0; i < SIZE; i++)
    {
        intArr[i] = 0 ;
    }
}

int hash::getProbes()       // returns number of linear probes
{
    return probes;
}

void introMsg();          // displays intro message
void menu(hash);          // displays options menu

int main()
{
    hash intArray;

    intArray.empty();

    intArray.populate();

    introMsg();

    intArray.display();

    cout << endl;

    menu(intArray);

    cout << endl << endl
         << "The number of linear probes when each number is hashed and "
         << "collision\noccurred when adding an element in the array is "
         << intArray.getProbes() << endl << endl
         <<"This hashing program was implemented by" << endl
         << "Colten Murray - 12 - 3 - 2018" << endl << endl;
    return 0;
}

void introMsg()
{
    cout << "Welcome to my Hashing Program"
         << endl << endl
         << "-----------------------------"
         << endl << endl
         << "A. Creates an integer array of size 30. Assigning * to each"
         << endl
         << "   location in the array indicating that the array is empty."
         << endl
         << "B. Populates 20 elements of the array with random integer values"
         << endl
         << "   88 and 525 inclusive."
         << endl
         << "C. If a collision occurs, linear probing will find the next"
         << endl
         << "   available position / location."
         << endl
         << "D. The generated array will be displayed in 2 lines."
         << endl
         << "   Each line contains 15 numbers seperated by 2 spaces."
         << endl << endl
         << "Generated Array"
         << endl
         << "---------------"
         << endl << endl;
}

void menu(hash intArr)
{
    char choice;
    bool quit = false;
    while(!quit)
    {
        bool correct = false;
        cout << "\n\nChoose from the following menu options" << endl << endl
            << "A. Display the generated array." << endl
            << "B. Search for a number (between 88-525) in the array." << endl
            << "C. Insert a new number (between 88-525) in the array." << endl
            << "D. Delete a number (between 88-525) in the array." << endl
            << "X. End the program." << endl << endl
            << "Choose your option: ";

             cin >> choice;

                switch(choice)
                {
                case 'A':
                case 'a':
                    cout << endl << "Displaying the generated array."
                        << endl << endl;
                    intArr.display();
                    cout << endl;
                    break;
                case 'B':
                case 'b':
                    intArr.search();
                    break;
                case 'C':
                case 'c':
                    intArr.insert();
                    break;
                case 'D':
                case 'd':
                    intArr.deleter();
                    break;
                case 'X':
                case 'x':
                    quit = true;
                    break;
                default :
                    cout << "\n*** Invalid Option ***" ;
                    break;
                  }
              }
}
