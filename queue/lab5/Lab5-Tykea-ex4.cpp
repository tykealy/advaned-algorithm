#include <iostream>
using namespace std;

struct Element
{
    string name;
    string sex;
    string number;
    Element *next;
};

struct Queue
{
    int n;
    Element *front, *rear;
};

Queue *createEmptyQueue()
{
    Queue *q = new Queue;
    q->n = 0;
    q->front = NULL;
    q->rear = NULL;

    return q;
}

void enqueue(Queue *q, string name, string sex, string number)
{
    Element *e = new Element;
    e->name = name;
    e->sex = sex;
    e->number = number;

    if (q->n == 0)
    {
        e->next = NULL;
        q->rear = e;
        q->front = e;
    }
    else
    {
        q->rear->next = e;
        q->rear = e;
    }
    q->n = q->n + 1;
}

void dequeue(Queue *q)
{
    if (q->n == 0)
    {
        cout << "Data Underflow." << endl;
    }
    else
    {
        Element *tmp = q->front;
        q->front = q->front->next;
        delete tmp;
        q->n = q->n - 1;
    }
}

void displayElement(Queue *q)
{
    Element *temp = q->front;
    if (q->n == 0)
        cout << "The queue is empty.";
    while (temp != NULL)
    {
        cout << endl;
        cout << temp->name << " " << temp->sex << " " << temp->number << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Queue *q = new Queue;
    q = createEmptyQueue();
    int choice = 0;
    while (choice == 0)
    {
        cout << "===========================" << endl;
        cout << "Welcome to tk restuarent!" << endl;
        cout << "Menu:" << endl;
        cout << "1. Add a customer to the queue." << endl;
        cout << "2. Remove a customer from queue." << endl;
        cout << "3. Display the queue." << endl;
        cout << "4.Exit the program." << endl;
        cout << "Enter a number to choose: ";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            string sex;
            string number;
            cout << "Enter the name:";
            cin >> name;
            cout << "Enter sex: ";
            cin >> sex;
            cout << "Enter phone number: ";
            cin >> number;
            enqueue(q, name, sex, number);
            choice = 0;
        }
        else if (choice == 2)
        {
            cout << "Serving a customer, " << q->front->name << endl;
            dequeue(q);
            choice = 0;
        }
        else if (choice == 3)
        {
            displayElement(q);
            choice = 0;
        }
        else
        {
            break;
        }
    }
}
