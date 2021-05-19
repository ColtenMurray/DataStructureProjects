//   Serial Number: 40
//
//   Author: Colten Murray
//
//   Due Date: 11/07/18
//   Programming Assignment Number 6
//
//   Fall 2018 - CS3358 - 002
//
//   Instructor: Husain Gholoom.
//
//   This program generates an array of a size inputted by the user, populated
//   by random numbers between 1-1000. Next, the program uses sequential search
//   to try to find 125 and then displays how long it took to do so. The
//   program then tests several sorting algorithms on the same array and
//   and displays the time statistics of those aswell.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// displays first prompt to user.
void firstPrompt();
// copies contents of one array to another.
void listReset(int [], int [], int);
// displays array to console.
void printList(int [], int);
// Recursive function for sequential searching.
int seqSearch(int [], int, int);
// Bubble sorts array and return number of swaps.
int bubbleSort(int [], int);
// insertion sorts array and returns number of comparisons.
int insertSort(int [], int);
// quick sorts array with the value nearest to the middle acting as the pivot.
int qmidSort(int [], int, int, int);
// quick sorts array with the first value acting as the pivot.
int qfirstSort(int [], int, int, int);
// quick sorts array with the last value acting as the pivot.
int qlastSort(int [], int, int, int);


int main()
{

    int input;  // size inputted by user.
    firstPrompt();
    cin >> input;
    cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "*** Error - Invalid input - Size must be > 0 ***"
                 << endl << endl << endl;
        }
        else if (input <= 0)
        {
            cout << "*** Error - Invalid input - Size must be > 0 ***"
                 << endl << endl << endl;
        }
        else
        {
            int numlist[input];
            int temp[input];
            clock_t beg;
            clock_t endt;
            int cycle;
            for(int i = 0; i < input; i++)
            {
                numlist[i] = rand() % 1000 + 1;
            }

            printList(numlist, input);
            listReset(temp, numlist, input);

            beg = clock();
            cycle = seqSearch(temp, 0, input);
            endt = clock();
            cout << "Start Time : "
                 << (float)beg/CLOCKS_PER_SEC << endl
                 << "End Time   : " << (float)endt/CLOCKS_PER_SEC << endl
                 << "Actual CPU Clock time : "
                 << (float)(endt - beg)/CLOCKS_PER_SEC << endl
                 << "Total Number of Comparisons : " << cycle
                 << endl << endl << endl;

            listReset(temp, numlist, input);

            beg = clock();
            cycle = bubbleSort(temp, input);
            endt = clock();
            cout << "Start Time : " << (float)beg/CLOCKS_PER_SEC << endl
                 << "End Time   : " << (float)endt/CLOCKS_PER_SEC << endl
                 << "Actual CPU Clock time : "
                 << (float)(endt - beg)/CLOCKS_PER_SEC << endl
                 << "Total Number of Swaps : " << cycle
                 << endl << endl << endl;

            listReset(temp, numlist, input);

            beg = clock();
            cycle = insertSort(temp, input);
            endt = clock();
            cout << "Start Time : " << (float)beg/CLOCKS_PER_SEC << endl
                 << "End Time   : " << (float)endt/CLOCKS_PER_SEC << endl
                 << "Actual CPU Clock time : "
                 << (float)(endt - beg)/CLOCKS_PER_SEC << endl
                 << "Total Number of Comparisons : " << cycle
                 << endl << endl << endl;

            listReset(temp, numlist, input);

            cout << "Quick Sort - Next to middle element as pivot"
                 << endl << endl;
            beg = clock();
            cycle = qmidSort(temp, 0, input - 1, 0);
            endt = clock();
            cout << "Start Time : " << (float)beg/CLOCKS_PER_SEC << endl
                 << "End Time   : " << (float)endt/CLOCKS_PER_SEC << endl
                 << "Actual CPU Clock time : "
                 << (float)(endt - beg)/CLOCKS_PER_SEC << endl
                 << "Total Number of Recursive Calls : " << cycle
                 << endl << endl << endl;

            listReset(temp, numlist, input);

            cout << "Quick Sort - First element as pivot"
                 << endl << endl;
            beg = clock();
            cycle = qfirstSort(temp, 0, input - 1, 0);
            endt = clock();
            cout << "Start Time : " << (float)beg/CLOCKS_PER_SEC << endl
                 << "End Time   : " << (float)endt/CLOCKS_PER_SEC << endl
                 << "Actual CPU Clock time : "
                 << (float)(endt - beg)/CLOCKS_PER_SEC << endl
                 << "Total Number of Recursive Calls : " << cycle
                 << endl << endl << endl;

            listReset(temp, numlist, input);

            cout << "Quick Sort - Last element as pivot"
                 << endl << endl;
            beg = clock();
            cycle = qlastSort(temp, 0, input-1, 0);
            endt = clock();
            cout << "Start Time : " << (float)beg/CLOCKS_PER_SEC << endl
                 << "End Time   : " << (float)endt/CLOCKS_PER_SEC << endl
                 << "Actual CPU Clock time : "
                 << (float)(endt - beg)/CLOCKS_PER_SEC << endl
                 << "Total Number of Recursive Calls : " << cycle
                 << endl << endl << endl;

        }

    cout << "Benchmark Algorithm Implemented by: Colten Murray," << endl
         << "12/7/2018" << endl << endl;
         return 0;
}

// displays first prompt to user.
void firstPrompt()
{
    cout << "Searching / Sorting Benchmark" << endl << endl
         << "Using a random number generator, we are creating an array of n"
         << endl << "elements of type integer then performin the following  :"
         << endl << endl << "   1. Display the first 20 numbers"
         << endl << endl << "   2. Using recursion, searching for an element in"
         <<" the array using" << endl <<"      sequential search and at the end"
         <<" displaying number of comparisons" << endl << "      it makes."
         << endl << endl << "   3. Sort the original array usinmg bubble sort"
         << " and at the end display" << endl << "      the number of swaps it"
         << " makes."<< endl << endl << "   4. Sorting the array using "
         << "insertion sort and at the end" << endl << "      displaying the "
         << "number of comparisons it makes." << endl << endl << "   5. "
         << "Sorting the array using quick sort and at the end displaying"
         << endl << "      the number of recursion calls it makes. Using the "
         << "next to the" << endl << "      midle value as a pivot value."
         << endl << endl << "   6. Sorting the same array using quick sort and "
         << "at the end" << endl << "      displaying the number of recursion "
         << "calls it makes. Using the" << endl << "      first value as a "
         << "pivot value." << endl << endl << "   7. Sorting the same array "
         << "using quick sort and at the end" << endl << "      displaying the "
         << "number of recursion calls it makes. Using the" << endl << "      "
         << "last value as a pivot value." << endl << endl << "   8. For each "
         << "of the preceding steps (2 thru 5), calculating and" << endl
         << "      printing the CPU time before each step starts and after each"
         << endl << "      completed step then calculating actual CPU time for "
         << "the" << endl << "      completion of each step" << endl << endl
         << endl << "Enter the size of the array : ";
}

// copies contents of one array to another.
// temp = copier array, numlist = copied array,
// n = array size

void listReset(int temp[], int numlist[], int n)
{
    for(int i = 0; i < n; i++)
        temp[i] = numlist[i];
}

// displays array to console
// numlist = array to be displayed
// n = size of array

void printList(int numlist[], int n)
{
    cout << "Array elements are :";
    for( int i = 0; i < n && i < 20 ; i++)
    {
        if(i == 11)
            cout << endl;
        cout << " " << numlist[i];
    }
    cout << endl << endl;
}

// Recursive function for sequential searching.
// numlist = array to be searched, counter = tracks number of comparisons
// n = size of array
int seqSearch(int numlist[], int counter, int n)
{
    if(counter == 0)
    {
        cout << "Sequential Search" << endl << endl
         << "Searching for 125..." << endl << endl;
    }

    if( numlist[counter] == 125 )
    {
        cout << "125 Was Found." << endl;
        return counter;
    }
    else if(counter == n - 1)
    {
        cout << "125 Was Not Found." << endl;
        return counter;
    }
    else
        seqSearch(numlist, counter+1, n);
}

// Bubble sorts array and return number of swaps.
// numlist = array to be sorted, n = array size

int bubbleSort(int numlist[], int n)
{
    bool swapped;
    int temp;
    int counter = 0;

    cout << "Bubble Sort : " << endl << endl;
    do
    {
        swapped = false;
        for( int i = 0; i < n - 1; i++)
        {
            if(numlist[i] > numlist[i+1])
            {
                swapped = true;
                temp = numlist[i];
                numlist[i] = numlist[i+1];
                numlist[i+1] = temp;
                counter++;
            }

        }
    }
    while(swapped);

    return counter;
}

// insertion sorts array and returns number of comparisons.
// numlist = array to be sorted, n = array size

int insertSort(int numlist[], int n)
{
    int counter = 0;

    cout << "Insertion Sort : " << endl << endl;

    for (int i = 1; i < n; i++)
    {
        int value = numlist[i],
            j = i - 1;
        while ( j >= 0 && numlist[j] > value)
        {
            numlist[j + 1] = numlist[j];
            j--;
            counter++;
        }
        numlist[j + 1] = value;
    }
    return counter;
}

// quick sorts array with the value nearest to the middle acting as the pivot.
// numlist = array to be sorted, left = left most index
// right = right most index, counter = keeps track of recursive calls
int qmidSort(int numlist[], int left, int right, int counter)
{

    int i = left;
    int j = right;
    int temp;
    int pivot = numlist[(left+right) / 2];

        while (i <= j)
        {
            while(numlist[i] < pivot)
                i++;
            while(numlist[j] > pivot)
                j--;
            if(i <= j)
            {
                temp = numlist[i];
                numlist[i] = numlist[j];
                numlist[j] = temp;
                i++;
                j--;
            }
        }

        if(left < j)
            counter++;
        if(i < right)
            counter++;

        if(left < j)
            qmidSort(numlist, left, j, counter);
        else if (i >= right)
            return counter;
        if(i < right)
            qmidSort(numlist, i, right, counter);
}

// quick sorts array with the first value acting as the pivot.
// numlist = array to be sorted, left = left most index
// right = right most index, counter = keeps track of recursive calls

int qfirstSort(int numlist[], int left, int right, int counter)
{
    int pivot = numlist[left];
    int i = (right + 1);
    int temp;

    for(int j = right; j >= left + 1; j--)
    {
        if(numlist[j] >= pivot)
        {
            i--;

            temp = numlist[i];
            numlist[i] = numlist[j];
            numlist[j] = temp;
        }
    }

    temp = numlist[i - 1];
    numlist[i - 1] = numlist[left];
    numlist[left] = temp;
    if ( (i - 2) > left)
        counter++;
    if ( i < right)
        counter++;

    if ( (i - 2) > left)
        qfirstSort(numlist, left, i - 2, counter);
    else if( i >= right)
        return counter;
    if ( i < right)
        qfirstSort(numlist, i, right, counter);
}

// quick sorts array with the last value acting as the pivot.
// numlist = array to be sorted, left = left most index
// right = right most index, counter = keeps track of recursive calls

int qlastSort(int numlist[], int left, int right, int counter)
{

    int pivot = numlist[right];    // pivot
    int i = (left - 1);  // Index of smaller element
    int temp;

    for (int j = left; j <= right- 1; j++)
    {
        if (numlist[j] <= pivot)
        {
            i++;

            temp = numlist[i];
            numlist[i] = numlist[j];
            numlist[j] = temp;
        }
    }

    temp = numlist[i + 1];
    numlist[i + 1] = numlist[right];
    numlist[right] = temp;

    if(i > left)
        counter++;
    if( (i + 2) < right)
        counter++;

    if(i > left)
        qlastSort(numlist, left, i, counter);
    else if((i+2) >= right)
        return counter;
    if( (i + 2) < right)
        qlastSort(numlist, i + 2, right, counter);
}
