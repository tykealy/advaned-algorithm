#include <iostream>

using namespace std;

struct Element
{
    string studentID;
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

void addElementToList(List *ls, string StudentID)
{
    Element *node = new Element;
    node->studentID = StudentID;
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
void displayElement(List *ls)
{
    Element *temp;
    temp = ls->head;
    while (temp != NULL)
    {
        cout << "Student ID: " << temp->studentID << endl;
        temp = temp->next;
    }
}

int main()
{
    List *list;

    list = createEmptyList();

    addElementToList(list, "IDTB080029");
    addElementToList(list, "IDTB080039");
    addElementToList(list, "IDTB080049");
    addElementToList(list, "IDTB080049");
    addElementToList(list, "IDTB080049");
    addElementToList(list, "IDTB080049");
    addElementToList(list, "IDTB080049");
    addElementToList(list, "IDTB080049");
    addElementToList(list, "IDTB080049");
    addElementToList(list, "IDTB080049");

    displayElement(list);
}