// Serial Number / s : xxxxxxxxx
//
// Author : (Your name here!!)
//
// Programming Assignment Number 4
//
// Fall 2019 - CS 3358 - Your Section Number
//
// Due Date :
//
// Instructor: Husain Gholoom.
//
// <Brief description of the purpose of the program>
#include <iostream>

using namespace std;

class stack
{
    private:
        struct Node
        {
            int value;    // int value stored in the node
            Node *link;   // address of the node
        };
        Node *head;       // beginning of linked list
    public:
        stack()
        {
            head = NULL;
        }
        ~stack()
        {
            Node *nodePtr;          // Pointer to traverse list
            Node *nextNode;         // Pointer holding address of node after
            nodePtr = head;
            head = NULL;
            while(nodePtr)
            {
                nextNode = nodePtr->link;
                delete nodePtr;
                nodePtr = nextNode;
            }
        }

        void appendNode(double num)
        {
            Node *newNode;               // Node to be added to list

            newNode = new Node;
            newNode->value = num;
            newNode->link = NULL;

            if(!head)
                head = newNode;
            else
            {
                Node *nodePtr;
                nodePtr = head;

                while(nodePtr->link)
                    nodePtr = nodePtr->link;

                nodePtr->link = newNode;
            }
        }

        void deleteNode()
        {

            Node *nodePtr;           // pointer to traverse list

            if(!head)
                cout << "List is empty!" << endl;
            else if(!head->link)
            {
                nodePtr = head;
                head = NULL;
                delete nodePtr;
            }
            else
            {
                Node *previousNode;    // pointer to hold address of trash node
                nodePtr = head->link;
                previousNode = head;
                while(nodePtr->link)
                {
                    previousNode = nodePtr;
                    nodePtr = nodePtr->link;
                }
                previousNode->link = NULL;
                delete nodePtr;
            }

        }
        void displayList()
        {
            Node *nodePtr;               // pointer to traverse list

            nodePtr = head;

            while(nodePtr)
            {
                cout << nodePtr->value << " ";

                nodePtr = nodePtr->link;
            }
        }

};
class queue
{
     private:
        struct Node
        {
            int value;             // int stored in Node
            Node *link;            // pointer holding Node address
        };
        Node *head;            // beginning of linked list

    public:
        queue()
        {
            head = NULL;
        }
        ~queue()
        {
            Node *nodePtr;            // pointer to traverse list
            Node *nextNode;           //pointer to hold node after
            nodePtr = head;
            head = NULL;
            while(nodePtr)
            {
                nextNode = nodePtr->link;
                delete nodePtr;
                nodePtr = nextNode;
            }
        }

        void appendNode(double num)
        {
            Node *newNode;                     // new Node to be added to list

            newNode = new Node;
            newNode->value = num;
            newNode->link = NULL;

            if(!head)
                head = newNode;
            else
            {
                Node *nodePtr;                  // pointer to traverse list
                nodePtr = head;

                while(nodePtr->link)
                    nodePtr = nodePtr->link;

                nodePtr->link = newNode;
            }
        }

        void deleteNode()
        {
            if(!head)
            {
                cout << " Queue is empty..." << endl;
            }
            else
            {
                Node *trashNode;             //pointer holding trash node
                Node *nodePtr;               // pointer holding new head
                nodePtr = head->link;
                trashNode = head;
                head = nodePtr;
                delete trashNode;
            }

        }

        void insertNode(int num, int index)
        {
            Node *newNode;                  // Node to be inserted into list

            newNode = new Node;
            newNode->value = num;

            Node *nodePtr;              // pointer to traverse list
            Node *linkNode;             // pointer to link list to new node
            if(index == 0)
            {
                linkNode = head;
                head = newNode;
                newNode->link = linkNode;
            }
            else
            {
                nodePtr = head;
                for (int i = 0; i < index - 1;i++)
                {
                    nodePtr = nodePtr->link;
                }

                linkNode = nodePtr->link;
                nodePtr->link = newNode;
                newNode->link = linkNode;
            }

        }

        void removeNode(int num)
        {
            if(!head)
            {
                cout << "List is empty!" << endl;
                return;
            }

            Node *nodePtr;         // pointer to traverse list
            if(head->value == num)
            {
                nodePtr = head;
                head = nodePtr->link;
                delete nodePtr;
            }
            else
            {
                Node *previousNode;
                nodePtr = head;

                while ( nodePtr && nodePtr->value != num)
                {
                    previousNode = nodePtr;
                    nodePtr = nodePtr->link;
                }

                if(nodePtr)
                {
                    previousNode->link = nodePtr->link;
                    delete nodePtr;
                }
                else
                {
                    cout << " Element not found..." << endl;
                }
            }

        }

        void findValues()
        {
            if(!head)
            {
                cout << "List is empty!" << endl;
            }
            else
            {
                int minVal = head->value;   // int value holding min element
                int maxVal = head->value;   // int value holding max element
                int total = head->value;    // total of all element values
                int counter = 1;            // # of elements in list
                int average;                // average of element values
                Node *nodePtr;             // pointer for traversing list

                nodePtr = head->link;

                while(nodePtr)
                {
                    counter++;
                    total += nodePtr->value;
                    if(nodePtr->value < minVal)
                        minVal = nodePtr->value;
                    if(nodePtr->value > maxVal)
                        maxVal = nodePtr->value;
                    nodePtr = nodePtr->link;
                }

                average = total/counter;

                cout << "Max value is " << maxVal << endl
                     << "Min value is " << minVal << endl
                     << "Average is " << average << endl;

            }

        }

        void displayList()
        {
            Node *nodePtr;                //pointer for traversing list

            nodePtr = head;

            while(nodePtr)
            {
                cout << nodePtr->value << " ";

                nodePtr = nodePtr->link;
            }
        }
};

int main()
{
    char choice;        // user's menu choice
    stack numStack;
    queue numQueue;

    while(choice != 'X')
    {

        cout << "*** Welcome to our Linked List Program ***" << endl << endl
             << "   A. Insert new element in the stack (LIFO). " << endl
             << "   B. Remove an element from the stack (LIFO)." << endl
             << "   C. Insert new element in the queue (FIFO)." << endl
             << "   D. Insert an element at specific location in the queue." << endl
             << "   E. Remove an element from the queue (FIFO)." << endl
             << "   F. Remove a specific element from the queue." << endl
             << "   G.Find Min element in the queue, Max element in the " << endl
             << "     queue, and the Average of the queue." << endl
             << "   H.Delete the entire stack." << endl
             << "   I. Delete the entire queue." << endl
             << "   X. Exit the program." << endl << endl
             << "Make a choice (capital letters only): ";

             cin >> choice;

             switch(choice)
             {

                case 'A':
                    int stackInput;
                    cout << "What int would you like to add to stack: ";
                    cin >> stackInput;
                    cout << " Adding to stack..." << endl;
                    numStack.appendNode(stackInput);
                    cout << "New Stack:" << endl;
                    numStack.displayList();
                    cout << endl << endl;
                    break;
                case 'B':
                    cout << " Removing top of stack..." << endl;
                    numStack.deleteNode();
                   cout << "New Stack:" << endl;
                    numStack.displayList();
                    cout << endl << endl;
                    break;
                case 'C':
                    int queueInput;
                    cout << "What int would you like to add to queue: ";
                    cin >> queueInput;
                    cout << " Adding to queue..." << endl;
                    numQueue.appendNode(queueInput);
                    cout << "New Queue:" << endl;
                    numQueue.displayList();
                    cout << endl << endl;
                    break;
                case 'D':
                    int value;
                    int index;
                    cout << "What int would you like to insert: ";
                    cin >> value;
                    cout << "What index would you like to insert it at: ";
                    cin >> index;
                    cout << " Inserting Element..." << endl;
                    numQueue.insertNode(value,index);
                    cout << "New Queue:" << endl;
                    numQueue.displayList();
                    cout << endl << endl;
                    break;
                case 'E':
                    cout << " Removing from front of queue..." << endl;
                    numQueue.deleteNode();
                    cout << "New Queue:" << endl;
                    numQueue.displayList();
                    cout << endl << endl;
                    break;
                case 'F':
                    int element;
                    cout << "What element would you like to remove: ";
                    cin >> element;
                    cout << " Removing " << element << " from queue...";
                    numQueue.removeNode(element);
                    cout << "New Queue:" << endl;
                    numQueue.displayList();
                    cout << endl << endl;
                    break;
                case 'G':
                    cout << "Queue:" << endl;
                    numQueue.displayList();
                    cout << endl << " Getting Queue Values..." << endl;
                    numQueue.findValues();
                    break;
                case 'H':
                    cout << " Deleting stack..." << endl;
                    numStack.~stack();
                    break;
                case 'I':
                    cout << " Deleting queue..." << endl;
                    numQueue.~queue();
                    break;
                case 'X':
                    cout << " Exiting program..." << endl;
                    break;
                default:
                    cout << "Please input a capital letter of one of the"
                         << " choices listed..." << endl;
         }
    }

    return 0;
}
