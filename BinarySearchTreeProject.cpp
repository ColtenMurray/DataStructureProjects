#include <iostream>

using namespace std;

class BinarySearchTree
{
public:
    int size;
    int* array;
    int arraySize;

    void insertNode(int x);
    int extendSize(int x);
    void display();
    void preOrder(int x);
    void postOrder(int x);
    void displayRSR();
    void displayLSR();
    void displayLeafValues();
    int treeLeafsCount();
    int getRight(int x);
    int getLeft(int x);
    int getParent(int x);

    BinarySearchTree(int size)
    {

        int newSize = extendSize(size);
        arraySize = size;
        array = new int[newSize];

        for(int x = 0; x < size; x++)
            array[x] = NULL;
    }
};

int BinarySearchTree::getLeft(int x)
{
    return x * 2 + 1;
}

int BinarySearchTree::getRight(int x)
{
    return x * 2 + 2;
}
int BinarySearchTree::getParent(int x)
{
    if(x % 2 == 0)
        return x / 2 - 1;
    else
        return (x - 1) / 2;
}

void BinarySearchTree::insertNode(int x)
{
    int index = 0;

    while(true)
    {
        if(array[index] == NULL)
        {
            array[index] = x;
            break;
        }
        else if(array[index] <= x)
        {
            if(array[index] == x)
            {
                cout << "ERROR!-- Repeating element" << endl;
                break;
            }
            index = (2 * index + 2);
        }
        else if(array[index] >= x)
        {
            if(array[index] == x)
            {
                cout << "ERROR!-- Repeating element" << endl;
                break;
            }
            index = (2 * index + 1);
        }
    }
}

int BinarySearchTree::extendSize(int x)
{
    int value = 0;
    for (int y = 0; y < x + 1; y++)
        value = (2* value) + 2;
    return value;
}

void BinarySearchTree::display()
{
    int count = 0;
    int x = 0;
    while(count < arraySize)
    {
        cout << x + 1 << ":  ";
        if(array[x] == NULL)
        {
            cout << "empty\n";
            x++;
        }

        else
        {
            cout << array[x] << endl;
            count++;
            x++;
        }
    }
    cout << "\n\n";
}

void BinarySearchTree::preOrder(int x)
{
    if(array[x] != NULL)
    {
        cout << array[x] << endl;
        preOrder(getLeft(x));
        preOrder(getRight(x));
    }
}

void BinarySearchTree::postOrder(int x)
{
    if(array[x] != NULL)
    {
        postOrder(getLeft(x));
        postOrder(getRight(x));
        cout << array[x] << endl;
    }
}

void BinarySearchTree::displayRSR()
{
    int index = 0;
    while(array[getRight(index)] != NULL )
    {
        index = getRight(index);
        cout << array[index] << endl;
    }
    cout << "\n\n";
}

void BinarySearchTree::displayLSR()
{
    int index = 0;
    while(array[getLeft(index)] != NULL)
    {
        index = getLeft(index);
        cout << array[index] << endl;
    }
    cout << "\n\n";
}

int BinarySearchTree::treeLeafsCount()
{
  int count = 0;
  int leaves = 0;
  for(int x = 0; count < arraySize; x++)
  {
      if( array[x] != NULL)
      {
          count++;
          if(array[getRight(x)] == NULL && array[getLeft(x)] == NULL)
          {
              leaves++;
          }
      }
  }
  return leaves;
}
void BinarySearchTree::displayLeafValues()
{
    int count = 0;
    for(int x = 0; count < arraySize; x++)
    {
        if( array[x] != NULL)
        {
            count++;
            if(array[getRight(x)] == NULL && array[getLeft(x)] == NULL)
            {
                cout << array[x] << endl;
            }
        }
    }
}

int main()
{
    BinarySearchTree tree(13);
    cout << "Binary Search Tree by Colten Murray\n\n"
         << "Inserting nodes.\n\n";
    tree.insertNode(70);
    tree.insertNode(50);
    tree.insertNode(100);
    tree.insertNode(30);
    tree.insertNode(60);
    tree.insertNode(80);
    tree.insertNode(110);
    tree.insertNode(20);
    tree.insertNode(68);
    tree.insertNode(90);
    tree.insertNode(120);
    tree.insertNode(25);
    tree.insertNode(62);

    cout << "Buinding BST is completed.\n\n"

         << "Values of the Binary Search Tree.\n\n";
    tree.display();


    //Pre-Order Traversal.
    cout << "Pre-Order Traversal of the BST:\n\n";
    tree.preOrder(0);
    cout << "\n\n";


    //Post-Order Traversal.
    cout << "Post-Order Traversal of the BST:\n\n";
    tree.postOrder(0);
    cout << "\n\n";


    //All right sub root values.
    cout << "Here are all right sub root values for the BST:\n\n";
    tree.displayRSR();


    //All left sub root values.
    cout << "Here are all left sub root values for the BST:\n\n";
    tree.displayLSR();


    //Counting Number of Leafs.
    cout << "\n\nNumber of Leafs = " << tree.treeLeafsCount();

    //Display the leaf values.
    cout << "\n\nHere are the leaf values in the BST:\n\n";
    tree.displayLeafValues();

    cout << "\n\n\nColten Murray- November 26, 2018\n\n";
    return 0;
}
