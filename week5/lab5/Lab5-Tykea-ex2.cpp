#include <iostream>
using namespace std;

struct Element
{
    string data;
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
int main()
{
    string text = "EAS*Y*QUE***ST***IO*N***";
    Queue *q = new Queue;
    q = createEmptyQueue();
    for (int i = 0; i < 25; i++)
    {
        int n = text[i];
        if (text[i] == '*')
        {
            dequeue(q);
        }
        else if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122))
        {
            enqueue(q, text[i]);
        }
    }

    cout << q->n << endl;
}
