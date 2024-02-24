#include <iostream>

using namespace std;

struct Element
{
    int number;
    Element *next;
};

struct List
{
    Element *tail, *head;
    int n;
};

List *createList()
{
    List *ls = new List;
    ls->head = NULL;
    ls->tail = NULL;
    ls->n = 0;
    return ls;
};

void addingElement(List *ls, int n)
{
    Element *box = new Element;
    box->number = n;
    if (ls->n == 0)
    {
        box->next = NULL;
        ls->head = box;
        ls->tail = box;
    }
    else
    {
        box->next = ls->head;
        ls->head = box;
    }
    ls->n = ls->n + 1;
}
void readList(List *ls)
{
    Element *tmp = ls->head;

    while (tmp != NULL)
    {
        cout << tmp->number << " ";
        tmp = tmp->next;
    }
}

void deleteElement(List *ls)
{
    if (ls->n == 0)
    {
        cout << "There is no data to delete." << endl;
    }
    else if (ls->n == 1)
    {
        ls->head = NULL;
        ls->tail = NULL;
        ls->n = ls->n - 1;
    }
    else
    {
        Element *tmp = ls->head;
        ls->head = tmp->next;
        delete tmp;
        ls->n = ls->n - 1;
    }
}
int main()
{
    List *list = createList();
    addingElement(list, 1);
    addingElement(list, 1);
    addingElement(list, 1);
    addingElement(list, 1);
    readList(list);
}
