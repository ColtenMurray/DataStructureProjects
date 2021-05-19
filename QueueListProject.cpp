//   Author : Colten Murray
//   Roster Number : 40
//   Due Date : 10/17/18
//   Programming Assignment Number 4
//   Fall 2018 - CS 3358 - 002
//
//   Instructor: Husain Gholoom.
//
//   This program creates a queue (FIFO) in which the user can add new elements
//   or delete existing ones. It also can display the queue size along with
//   the minimum, maximum, and average of the elements.


#include <iostream>
#include <string>

using namespace std;


class queueList
{
private:
    int queuesize;            //Number of elements in the queue
    int Min;                  // element with the smallest value
    int Max;                  // element with the largest value
    int Avg;                  // average value of all elements in queue
    struct Node
    {
        int data;             // value assigned to the node
        Node *link;           // pointer for linking nodes
    };
    Node *head;               // the first node in the queue
public:
    queueList();              // definition of a new Queue List
    void deleteQueue();       // deletes all elements in the queue
    void enqueue(int);        // adds new element to back of queue
    void enqueueAT(int, int); // inserts new element into specific location in
                              // queue.
    void dequeue();           // removes element from front of queue
    void dequeueAT(int);      // removes specific element from queue
    void findValues();        // finds values for min, max, and average
    void getMin();             // displays smallest element in queue
    void getMax();             // displays largest element in queue
    void getAvg();             // displays average of all elements in queue
    void getSize();            // displays the size of the queue
    int returnSize();          // returns the size of the queue
    int returnHead();          // returns value of element in the front of queue
    void display();
};

queueList::queueList()        // definition of a new Queue List
{
    head = NULL;
}
void queueList::deleteQueue() // deletes all elements in the queue
{
    while(head)
    {
        dequeue();
    }
}
void queueList::display()
{
    Node *nodePtr;
    nodePtr = head;
    while(nodePtr)
    {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->link;
    }
    cout << endl;
}
void queueList::enqueue(int num) // adds new element to back of queue
{                                // num = the element value to be added
    Node *newNode;
    newNode = new Node;  // new node to be added to back of queue
    newNode->data = num;
    newNode->link = NULL;
    if(!head)
    {
        head = newNode;
    }
    else
    {
        Node *nodePtr;
        nodePtr = head;
        while( nodePtr->link)
            nodePtr = nodePtr->link;
        nodePtr->link =newNode;
    }
}
void queueList::enqueueAT(int insertion,int num)// inserts new element into
{                                               // specific location in queue.
    Node *newNode;  // node to be inserted.    |// insertion = the value
    Node *nodePtr;  // pointer to keep track   |
                    //of current node.         |// of the new element.
    Node *previousNode;//pointer to keep track |// num = location of new element
                       // of previous node.    |
    newNode = new Node;
    newNode->data = insertion;
    if(!head)
    {
        head = newNode;
        newNode->link = NULL;
    }
    else
    {
        nodePtr = head;
        previousNode = NULL;
        int nodeCount = 0;
        while(nodePtr && nodeCount < (num-1))
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->link;
            nodeCount++;
        }
        if (previousNode == NULL)
        {
            head = newNode;
            newNode->data = insertion;
            newNode->link = nodePtr;
        }
        else
        {
            previousNode->link = newNode;
            newNode->data = insertion;
            newNode->link = nodePtr;
        }
    }
}

void queueList::dequeue()       // removes element from front of queue
{
    if(!head)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node *nodePtr;              // pointer to node to be deleted
    nodePtr = head;
    head = nodePtr->link;

    delete nodePtr;
}

void queueList::dequeueAT(int num)   // removes specific element from queue
{                                    // num = the element to be removed
    if(!head)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node *nodePtr;                  // pointer to keep track of current node.

    if(head->data == num)
    {
        nodePtr = head;
        head = nodePtr->link;

        delete nodePtr;
    }
    else
    {
        Node *previousNode;
        nodePtr = head;

        while(nodePtr && nodePtr->data != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->link;
        }

        if(nodePtr)
        {
            previousNode->link = nodePtr->link;
            cout << "Element " << num <<" deleted!";

            delete nodePtr;
        }
        else
        {
            cout << "Element not found!" << endl;
        }
    }
}

void queueList::findValues()    // finds values for min, max, and average
{
    Node *nodePtr;
    nodePtr = head;
    int nodeCount = 0;          // counts number of nodes in queue
    int nodeTotal = 0;          // total of all values in queue


    if(head)
    {
        Min = nodePtr->data;        // min value in queue
        Max = nodePtr->data;        // max value in queue
       while(nodePtr)
        {
            if(nodePtr->data < Min)
            {
                Min = nodePtr->data;
            }
            if(nodePtr->data > Max)
            {
                Max = nodePtr->data;
            }

            nodeTotal += nodePtr->data;
            nodeCount++;
            nodePtr = nodePtr->link;
        }

        queuesize = nodeCount;
        Avg= nodeTotal / nodeCount;
    }
    else
    {
        Min = 0;
        Max = 0;
        Avg = 0;
        queuesize = 0;
    }

}

void queueList::getMin()     // displays smallest element in queue
{
    if(queuesize > 0)
    {
        cout << "Min element is: " << Min << endl;
    }
}

void queueList::getMax()     // displays largest element in queue
{
    if(queuesize > 0)
    {
        cout << "Max element is: " << Max << endl;
    }
}

void queueList::getAvg()     // displays average of all elements in queue
{
    if(queuesize > 0)
    {
        cout << "Average of all elements is: " << Avg << endl;
    }
    else
    {
        cout << "Queue is currently empty!"<< endl;
    }
}

void queueList::getSize()    // displays the size of the queue
{
    if(queuesize == 0)
    {
        cout << "Queue is currently empty!" << endl;
    }
    else
    {
        cout << "The size of the queue is: " << queuesize << endl;
    }
}

int queueList::returnSize()      //returns size of queue as int.
{
    return queuesize;
}
int queueList::returnHead()
{
    return head->data;
}

int main()
{
    string choice;        // User's choice in string format to handle input of
                          // more than one character.
    char ans;             // User's menu choice
    queueList list;       // declaration of the queue

    while( ans != 'x' && ans != 'X')
    {

        cout << "A.Insert new element in the queue(FIFO)." << endl
             << "B.Insert an element at specific location in the queue." << endl
             << "C.Remove an element from the queue(FIFO.)" << endl
             << "D.Remove a specific element from the queue." << endl
             << "E.Find Min element in the queue, max Element in the" << endl
             << "  queue, and the Average of the queue." << endl
             << "F.Display the size of the queue." << endl
             << "G.Delete the entire list" << endl
             << "X.Exit the program" << endl;
        cin >> choice;

        bool answered = false; // bool for if the user gave a sufficient answer.
        bool correct = false; // bool for if user's input is in correct format.
        while(!answered)
        {
            while(!correct)
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(choice.max_size()*CHAR_MAX,'\n');
                    cout << "Error*** wrong input. please choose a correct"
                         << " character." << endl << endl;
                    cin >> choice;
                }
                else if(choice.length() != 1)
                {
                    cin.clear();
                    cin.ignore(choice.max_size()*CHAR_MAX,'\n');
                    cout << "Error*** wrong input. please choose a correct"
                         << " character." << endl << endl;
                    cin >> choice;
                }
                else
                {
                    ans = choice.at(0);
                    correct = true;
                }

            }

            switch(ans)
            {
            case 'a':
            case 'A':
                answered = true;
                int num;               // element to be inserted into queue
                cout << endl;
                cout << "Enter an element to insert into queue (FIFO): ";
                cin >> num;
                cout << endl;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                    cout << "Error*** wrong input. please choose an integer"
                         <<  endl;
                    cin >> num;
                }
                list.enqueue(num);
                break;
            case 'b':
            case 'B':
                list.findValues();
                int numInsert;        // element to be inserted into queue
                int place;            // location in que in which to insert
                cout << endl;
                cout << "Enter an element to insert into queue (FIFO): ";
                cin >> numInsert;
                cout << endl;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                    cout << "Error*** wrong input. please choose an integer."
                         << endl;
                    cin >> numInsert;
                }
                cout << "Enter a location to insert into queue (FIFO): ";
                cin >> place;
                while(cin.fail() || place < -1 || place > list.returnSize())
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(INT_MAX,'\n');
                        cout << "Error*** wrong input. please choose an integer."
                             << endl;
                        cin >> place;
                    }
                   else
                   {
                       cout << "Error*** wrong input. Location out of index."
                            << "Choose another location"<< endl;
                        cin >> place;
                   }
                }
                list.enqueueAT(numInsert, place);
                cout << endl;
                answered = true;
                break;
            case 'c':
            case 'C':
                answered = true;
                cout << endl;
                cout << "Element " << list.returnHead() << " deleted!";
                list.dequeue();
                cout << endl << endl;
                break;
            case 'd':
            case 'D':
                int element;           // element chosen by user to be removed
                cout << endl;
                cout <<"Enter a element to remove: ";
                cin >> element;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                    cout << "Error*** wrong input. please choose an integer"
                         << endl;
                    cin >> element;
                }
                list.dequeueAT(element);
                cout << endl << endl;
                answered = true;
                break;
            case 'e':
            case 'E':
                answered = true;
                list.findValues();
                cout << endl;
                list.getMin();
                list.getMax();
                list.getAvg();
                cout << endl;
                break;
            case 'f':
            case 'F':
                answered = true;
                list.findValues();
                cout << endl;
                list.getSize();
                cout << endl;
                break;
            case 'g':
            case 'G':
                answered = true;
                list.deleteQueue();
                list.display();
                cout << "Queue has been deleted!" << endl << endl;
                break;
            case 'x':
            case 'X':
                answered = true;
                break;
            default:
                cout << "Error*** wrong input. please choose a correct"
                     << " character." << endl;
                cin >> ans;
                break;
            }
        }
    }
    cout << endl << "This LL / Queue Program is Implemented By :" << endl
                 << "Colten Murray - October 17, 2018" << endl << endl;

    return 0;
}
