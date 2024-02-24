#include <iostream>

using namespace std;

struct Element
{
    string alphabet;
    Element *next, *previous;
};

struct List
{
    Element *head, *tail;
    int n;
};

List *createEmptyList()
{
    List *ls = new List;
    ls->head = NULL;
    ls->tail = NULL;
    ls->n = 0;
    return ls;
}

void inserFromHead(List *ls, char alphabet)
{
    Element *box = new Element;
    box->alphabet = alphabet;
    box->previous = NULL;

    if (ls->n == 0)
    {
        box->next = NULL;
        ls->head = box;
        ls->tail = box;
    }
    else
    {
        ls->head->previous = box;
        box->next = ls->head;
        ls->head = box;
    }
    ls->n = ls->n + 1;
}

void readListFromTail(List *ls)
{
    Element *tmp = ls->tail;
    while (tmp != NULL)
    {
        cout << tmp->alphabet << " ";
        tmp = tmp->previous;
    }
}

void readListFromHead(List *ls)
{
    Element *tmp = ls->head;
    while (tmp != NULL)
    {
        cout << tmp->alphabet << " ";
        tmp = tmp->next;
    }
}
int main()
{
    List *list = new List;
    for (int i = 65; i <= 90; i++)
    {
        inserFromHead(list, char(i));
    }

    readListFromTail(list);
    cout << endl;
    readListFromHead(list);
}