#include <iostream>

using namespace std;

struct Element
{
    int num;
    Element *next;
};

struct List
{
    Element *tail, *head;
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

void addElementToList(List *ls, int num)
{
    Element *node = new Element;
    node->num = num;
    if (ls->n == 0)
    {
        node->next = NULL;
        ls->head = node;
        ls->tail = node;
    }
    else
    {
        node->next = ls->head;
        ls->head = node;
    }
    ls->n = ls->n + 1;
}
void addElementToListEnd(List *ls, int num)
{
    Element *node = new Element;
    node->num = num;
    if (ls->n == 0)
    {
        node->next = NULL;
        ls->head = node;
        ls->tail = node;
    }
    else
    {
        ls->tail->next = node;
        ls->tail = node;
    }
    ls->n = ls->n + 1;
}
void displayElement(List *ls)
{
    Element *temp;
    temp = ls->head;
    while (temp != NULL)
    {
        cout << temp->num;
        temp = temp->next;
    }
}

int main()
{
    List *list;

    list = createEmptyList();

    addElementToList(list, 7);
    addElementToList(list, 1);
    displayElement(list);
    cout << endl;
    addElementToListEnd(list, 0);
    addElementToListEnd(list, 4);
    displayElement(list);
}