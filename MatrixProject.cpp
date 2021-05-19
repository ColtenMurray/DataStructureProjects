#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void fillMatrix(vector<vector<int> > &, int);
void displayMatrix(vector<vector<int> >, int);

int main()
{

    int n;

    cout << "Welcome to my perfect matrix program. The function of the program "
         << "is to:" << endl << endl
         << "   1. Allow the user to enter the size of the perfect matrix, "
         << "such as N. N>=2 and <=10."  << endl
         << "   2. Create a 2D vector array of size N x N."
         << "   3. Populate the 2 D vector array with distinct random numbers."
         << endl
         << "   4. Display the perfect number, sum for each row, column, and "
         << "diagonals then determine whether the numbers in N x N vector array"
         << " are perfect matrix numbers." << endl << endl
         << "Enter the size of the matrix : ";
         cin >> n;

    vector<int> rows(n);
    vector<vector<int> > matrix(n,rows);


    fillMatrix(matrix, n);

    cout << endl << "The perfect matrix that is created for size " << n << " :"
         << endl;

    displayMatrix(matrix, n);






}

void fillMatrix( vector<vector<int> > &matrix , int n)
{

    vector<int> used;
    int value;
    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            bool distinct = true;

            do
            {

                value = rand()%(n*n);

                for(int k = 0; k < (int)used.size(); k++)
                {
                    if( value == used.at(i))
                        distinct = false;
                }

            }
            while(!distinct);


            matrix[i][j] = value;
            used.push_back(value);

        }
    }
}

void displayMatrix(vector<vector<int> > matrix, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl << endl;
    }
}
