#include <iostream>
using namespace std;

struct Element
{
    int task;
    string description;
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

void enqueue(Queue *q, int task, string description)
{
    Element *e = new Element;
    e->task = task;
    e->description = description;

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
        cout << tmp->description << endl;
        delete tmp;
        q->n = q->n - 1;
    }
}

int main()
{
    int ask = 0;
    string ans;
    Queue *q = new Queue;
    q = createEmptyQueue();
    enqueue(q, 2, "Doing task 2...Done!");
    enqueue(q, 1, "Doing task 1...Done!");
    enqueue(q, 4, "Doing task 4...Done!");
    enqueue(q, 3, "Doing task 3...Done!");

    while (ask == 0)
    {
        cout << "Do you want to perform task in your queue now?" << endl;
        cin >> ans;
        if (ans == "no")
            break;
        if (ans == "yes")
        {
            dequeue(q);
        }
    }
}