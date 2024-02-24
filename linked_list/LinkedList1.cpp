#include <iostream>

using namespace std;

struct Element
{
    string name;
    int age;
    Element *next;
};

struct List
{
    int n;
    Element *head, *tail;
};

List *creatEmptyList()
{
    List *lsPtr;
    lsPtr = new List;
    lsPtr->n = 0;
    lsPtr->head = NULL;
    lsPtr->tail = NULL;

    return lsPtr;
}

void addingElementFromTheStart(List *lsPtr, string name, int age)
{
    Element *box;
    box = new Element;
    (*box).age = age;
    box->name = name;
    if (lsPtr->n == 0)
    {
        box->next = NULL;
        lsPtr->head = box;
        lsPtr->tail = box;
        lsPtr->n = lsPtr->n + 1;
    }
    else
    {
        box->next = lsPtr->head;
        lsPtr->head = box;
        lsPtr->n = lsPtr->n + 1;
    }
}
void addingElementFromTheEnd(List *lsPtr, string name, int age)
{
    Element *box;
    box = new Element;
    box->age = age;
    box->name = name;
    if (lsPtr->n == 0)
    {
        box->next = NULL;
        lsPtr->head = box;
        lsPtr->tail = box;
        lsPtr->n = lsPtr->n + 1;
    }
    else
    {
        lsPtr->tail->next = box;
        lsPtr->tail = box;
        lsPtr->n = lsPtr->n + 1;
    }
}
void displayList(List *lsPrt)
{
    Element *t;
    t = lsPrt->head;
    while (t != NULL)
    {
        cout << t->name << " is " << t->age << endl;
        t = t->next;
    }
}

int main()
{
    List *L1;
    L1 = creatEmptyList();
    addingElementFromTheEnd(L1, "tykeaboyloy", 19);
    addingElementFromTheEnd(L1, "Ponleu", 20);
    addingElementFromTheEnd(L1, "vanneath", 21);

    displayList(L1);
}