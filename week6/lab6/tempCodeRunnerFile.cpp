#include <iostream>
using namespace std;
struct Element
{
    char data;
    Element *next;
};

struct Stack
{
    int n;
    Element *top;
};

Stack *createEmptyStack()
{
    Stack *st = new Stack;
    st->n = 0;
    st->top = NULL;

    return st;
}

void push(Stack *st, char data)
{
    Element *e = new Element;
    e->data = data;
    if (st->n == 0)
    {
        e->next = NULL;
        st->top = e;
    }
    else
    {
        e->next = st->top;
        st->top = e;
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
        e = st->top;
        st->top = e->next;
        delete e;
        st->n = st->n - 1;
    }
}

void displayElement(Stack *st)
{
    Element *temp = st->top;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}