#include <iostream>
using namespace std;

struct Element
{
    int data;
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

void enqueue(Queue *q, int data)
{
    Element *e = new Element;
    e->data = data;

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

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
