//   Author : Colten Murray
//   Roster Number : 40
//   Due Date : 09/19/18
//   Programming Assignment Number 2
//   Fall 2018 - CS 3358 - 002
//
//   Instructor: Husain Gholoom.
//
//   This program generates a matrix of size n * n filled randomly with 1s and
//   0s. The user is then asked to specify an element in the matrix in the
//   i-th, j-th spot to search around for 1s.

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void fillMatrix(vector< vector<int> > &matrix, int);
// fills the matrix randomly with 1s and 0s
void sizeMatrix(vector< vector<int> > &matrix, int);
// sets the size of the matrix
void printMatrix(vector< vector<int> > matrix, int);
// prints the matrix to the console
int searchSpot(vector< vector<int> > matrix, int , int, int n);
// searches for ones around the element in the [i][j] place

int main()
{
    cout << "You are given an n x n array whose elements are either 0 or 1."
         << endl << "The program then will ask for two integer indices i and j"
         << endl << "(less or equal to n or -1) and will return the number of "
         << "nonzero" << endl<< endl << endl << "elements of the array that are"
         <<" adjacent to " << "the i-th and j-th" << endl << "element."
         << endl << endl;

    bool repeat = true; // boolean that controls whether to loop setting the
                        // array size or not.

    while(repeat)
    {
        int n = 1; // n represents the size of the matrix set by n x n

        cin.clear();
        cin.ignore(INT_MAX,'\n');

        cout << "Enter the size of the array ( >1 or 0 to quit ) : ";
        cin >> n;

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "Invalid. Array size must be an integer >1 or 0 to quit"
            << endl << endl;
            cin >> n;
        }
        if(n == 0)
        {
            repeat = false;
        }
        else if(n <=1 )
        {
            cout << "Invalid. Array size must be an integer >1 or 0 to quit"
                 << endl << endl;
            cin >> n;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cout << "Invalid. Array size must be an integer >1 or 0 to quit"
                     << endl << endl;
                cin >> n;
            }

        }
        else
        {

            vector<int> cols; // vector of ints that will represent the columns
                              // of the array
            vector< vector<int> > matrix(0,cols); // initialization of the main
                                                  // matrix

            sizeMatrix(matrix, n);
            fillMatrix(matrix, n);
            printMatrix(matrix, n);

            bool repeat2 = true; //boolean which controls whether or not to loop
                                 // getting coordinates from the user.

            while(repeat2)
            {
                cout << "Enter two integer indices i and j (between 1 and n)"
                     <<" or -1" <<" to exit"<< endl << endl;

                int i; // the i-th index
                int j; // the j-th index
                int ans; // number of ones found

                cin >> i >> j;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                    if(i != -1 && j != -1)
                    {
                        cout << "Invalid. Indices must be between {0 and n ) or"
                             <<" -1 to exit" << endl << endl;
                        cin >> i >> j;
                    }
                }

                bool repeat3 = true;//boolean which controls whether or not
                                    //to loop getting coordinates from the user

                while(repeat3)
                {

                    if( i == -1 || j == -1)
                    {
                        repeat2 = false;
                        repeat3 = false;
                    }
                    else if (i >= 1 && j >= 1 && i <= n && j <= n)
                    {
                        ans = searchSpot(matrix, i, j, n);
                        cout << endl << "Number of nonzero elements that are"
                             <<" adjacent to" << " i =" << i << ", j ="
                             << j << " are   " << ans << endl << endl;
                        repeat3 = false;
                    }

                    else
                    {
                        cout << "Invalid. Indices must be between {0 and n )"
                             <<" or -1 to exit" << endl << endl;
                        cin >> i >> j;
                        while(cin.fail() && i != -1 && j != -1)
                        {
                            cin.clear();
                            cin.ignore(INT_MAX,'\n');
                            cout << "Invalid. Indices must be between "
                                 <<"{0 and n ) or -1 to exit" << endl << endl;
                            cin >> i >> j;
                        }
                    }
                }
             }
           }
        }

    return 0;
}

//**************************************************************************
// this function fills the matrix randomly with 1s and 0s.
//
// matrix is the 2d int vector used for the matrix.
// int n is the integer that represents the size of the matrix set by n x n.
//**************************************************************************
void fillMatrix(vector< vector<int> > & matrix, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp = rand() % 2;
            matrix[i][j] = temp;
        }

    }

}

//**************************************************************************
// this function sets the size of the matrix according to n x n.
//
// matrix is the 2d int vector used for the matrix.
// int n is the integer that represents the size of the matrix set by n x n.
//**************************************************************************
void sizeMatrix(vector <vector<int> > & matrix, int n)
{
    matrix.resize( n , vector<int>( n ));
}

//**************************************************************************
// this function prints the matrix to the console.
//
// matrix is the 2d int vector used for the matrix.
// int n is the integer that represents the size of the matrix set by n x n.
//**************************************************************************
void printMatrix(vector< vector<int> > matrix, int n)
{
    cout << endl << endl;
    for (int i = 0; i< n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//**************************************************************************
// this function searches for ones around the matrix[i][j] element.
//
// matrix is the 2d int vector used for the matrix.
//int i is the i-th index to be searched
//int j is the j-th index to be searched
// int n is the integer that represents the size of the matrix set by n x n.
// returns number of ones found represented as an integer.
//**************************************************************************
int searchSpot(vector< vector<int> > matrix, int i, int j, int n)
{
    int count = 0;
    for(int x = i-2; x <= i; x++)
    {
        for(int y = j-2; y <=j; y++ )
        {
            if( x >= 0 && y >=0 && x < n && y < n)
            {
                if(x != i && y != j)
                {
                    if( matrix[x][y] == 1)
                    {
                    count += 1;
                    }
                }

            }
        }
    }
   return count;
}
