#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element *next;
};

struct Stack
{
    int n;
    Element *end;
};

Stack *createEmptyStack()
{
    Stack *st = new Stack;
    st->n = 0;
    st->end = NULL;

    return st;
}

void push(Stack *st, int data)
{
    Element *e = new Element;
    e->data = data;
    if (st->n == 0)
    {
        e->next = NULL;
        st->end = e;
    }
    else
    {
        e->next = st->end;
        st->end = e;
    }
    st->n = st->n + 1;
}

void pop(Stack *st)
{
    if (st->n == 0)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        Element *e = new Element;
        e = st->end;
        st->end = e->next;
        delete e;
        st->n = st->n - 1;
    }
}

void displayElement(Stack *st)
{
    Element *temp = st->end;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
