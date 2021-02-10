/**
 * A sample code of Creating C++ linked lists,
 * Including definitions the list node class and linked list class,
 * and how to create a blank linked list and a one-node linked list.
 *
 * Outline: understand the definition and structure of the linked
 * list and build a linked list based on it.
 */

#include <iostream>
#include <cstddef>
using std::cout;
using std::endl;


/* definition of the list node class */
class Node
{
    friend class LinkedList; 
private:
    int value;  
    Node *pNext;
    Node *pPrev; //points at previous node 
    
public:
    /* Constructors with No Arguments */
    //added a previous pointer
    Node()
        : pNext(NULL), pPrev(NULL) 
    { }
    
    /* Constructors with a given value */
    //added a previous pointer
    Node(int val)
        : value(val), pNext(NULL), pPrev(NULL)
    { }
    
    /* Constructors with a given value and a link of the next node */
    //added a previous pointer
    Node(int val, Node *next, Node *prev)
        : value(val), pNext(next), pPrev(prev)
    { }
    
    /* Getters */
    int getValue() { return value; }
    
    Node *getNext() { return pNext; }
    Node *getPrev() { return pPrev; }
};

/* definition of the linked list class */
class LinkedList
{
private:
    /* pointer of head node */
    Node *pHead;
    /* pointer of tail node */
    Node *pTail;
    //variable stores the number of integers in the list
    int list_size;
    
public:
    /* Constructors with No Arguments */
    LinkedList();
    /* Constructors with a given value of a list node */
    LinkedList(int val);
    /* Destructor */
    ~LinkedList();
    
    /* Traversing the list and printing the value of each node */
    void traverse_and_print();

    void push_back(int val);
    
    //this method allows you to access the value of a previous node 
    void print_prev(int val);
    //this method allows you to access the value of the next node
    void print_next(int val);
};

LinkedList::LinkedList()
{
    /* Initialize the head and tail node */
    pHead = pTail = NULL; 
}

LinkedList::LinkedList(int val)
{
    /* Create a new node, acting as both the head and tail node */
    Node *p = new Node(val);
    pHead = pTail = p;
    list_size++;//the size of the list will now be 1
}

LinkedList::~LinkedList()
{
}

void LinkedList::traverse_and_print()
{
    Node *p = pHead; 
    
    /* The list is empty? */
    if (pHead == NULL) 
    {
        cout << "The list is empty" << endl;
        return ;
    }
    
    cout << "LinkedList: " << endl;
    /* A basic way of traversing a linked list */
    while (p != NULL)  /* while there are some more nodes left */
    {
        /* output the value */
        cout << p->value;
        /* The pointer moves along to the next one */
        p = p->pNext;
        cout << " "; //added space between node values
    }
    cout << endl;
}

void LinkedList::push_back(int val)
{
    Node *p = new Node(val);
    
    if(pHead == NULL)
    {
        pHead = p;
        pTail = p;
    }
    else
    {
        p->pPrev = pTail;  //the "previous" pointer in new node will point at the current tail node
        pTail->pNext = p;  //the "next" pointer in the current tail will point at the new node  
        pTail = p; //new node now acts as the tail node
    }
    list_size++; //list size will increase by 1 each time this method runs
}

void LinkedList::print_prev(int val)
{
    //new node created that shares the address of the head node
    Node *p = pHead;
    //if one asks to print the value of the node before the header
    if(val == 1)
        cout << "Selected head node - no previous value" << endl;
    //if one asks to print the previous value of a node that does not exist
    else if(val > list_size)
        cout << "INVALID ENTRY - Node " << val << " does not exist" << endl;
    //if one asks to print the value of a previous node from a node that exists and is not the header
    else
    {
        for(int i {1}; i < val; i++)
        {
            p = p->pNext;
        }
        cout << "The value before Node " << val << ": " << p->pPrev->value << endl;
    }
}

void LinkedList::print_next(int val)
{
    //new node created that shares the address of the head node
    Node *p = pHead;
    //if one asks to print the value of the node after the tail
    if(val == list_size)
        cout << "Selected tail node - no next value" << endl;
    //if one asks to print the next node of a node that does not exist
    else if(val > list_size)
        cout << "INVALID ENTRY - Node " << val << " does not exist" << endl;
    //if one asks to print the value of a next node from a node that exists and is not the tail
    else
    {
        for(int i {1}; i < val; i++)
        {
            p = p->pNext;
        }
        cout << "The value after Node " << val << ": " << p->pNext->value << endl;
    }
}

int main(int argc, const char * argv[])
{
    /* Create an empty list */
    LinkedList list1;
    cout << "Created an empty list named list1." << endl;
    /* output the result */
    cout << "list1:" << endl;
    list1.traverse_and_print();
    
    /* Create a list with only one node */
    LinkedList list2(10);
    cout << "Created a list named list2 with only one node." << endl;
    /* output the result */
    cout << "list2:" << endl;
    list2.traverse_and_print();

    /*your testing code here*/
    for (int i = 0 ; i < 10; i++)
    {
        list2.push_back(i);
    }
    list2.traverse_and_print();
    
    //tests all of the new methods
    list2.print_prev(1);
    list2.print_prev(11);
    list2.print_prev(13);
    list2.print_next(1);
    list2.print_next(11);
    list2.print_next(13);
    
    return 0;
}


