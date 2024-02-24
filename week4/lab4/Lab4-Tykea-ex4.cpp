#include <iostream>
#include <fstream>

using namespace std;

struct Element
{
    int num;
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

void insertFromHead(List *ls, int num)
{
    Element *box = new Element;
    box->num = num;
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

void insertFromTail(List *ls, int num)
{
    Element *box = new Element;
    box->num = num;
    box->next = NULL;

    if (ls->n == 0)
    {
        box->previous = NULL;
        ls->head = box;
        ls->tail = box;
    }
    else
    {
        box->previous = ls->tail;
        ls->tail->next = box;
        ls->tail = box;
    }
    ls->n = ls->n + 1;
}

void WriteListToFile(List *ls, int searching, int searchResult)
{
    fstream outputFile;
    outputFile.open("Output-Ex4-Tykea.txt", ios::app);
    Element *tmp = ls->head;

    while (tmp != NULL)
    {
        outputFile << tmp->num << endl;
        tmp = tmp->next;
    }
    outputFile << "'" << searching << "'"
               << " appears " << searchResult << " times in the list." << endl;
    outputFile.close();
}

void deleteElementFromHead(List *ls)
{
    Element *tmp = ls->head;

    if (ls->n == 0)
    {
        cout << "No data to delete." << endl;
    }
    else if (ls->n == 1)
    {
        ls->head = NULL;
        ls->tail = NULL;
    }
    else
    {
        ls->head = tmp->next;
        ls->head->previous = NULL;
        delete tmp;
    }
    ls->n = ls->n - 1;
}
void deleteElementFromTail(List *ls)
{
    Element *tmp = ls->tail;

    if (ls->n == 0)
    {
        cout << "No data to delete." << endl;
    }
    else if (ls->n == 1)
    {
        ls->head = NULL;
        ls->tail = NULL;
    }
    else
    {
        ls->tail = tmp->previous;
        ls->tail->next = NULL;
        delete tmp;
    }
    ls->n = ls->n - 1;
}
int searchCount(List *ls, int n)
{
    int count = 0;
    Element *tmp = ls->head;
    while (tmp != NULL)
    {
        if (tmp->num == n)
        {
            count = count + 1;
        }
        tmp = tmp->next;
    }
    return count;
}
int main()
{
    List *ls = createEmptyList();

    insertFromHead(ls, 1);
    insertFromTail(ls, 2);
    insertFromTail(ls, 3);
    insertFromHead(ls, 4);
    insertFromTail(ls, 5);
    insertFromTail(ls, 1);
    insertFromHead(ls, 1);
    insertFromHead(ls, 2);
    deleteElementFromTail(ls);
    deleteElementFromHead(ls);
    int searching = 1;
    int searchResult = searchCount(ls, searching);

    WriteListToFile(ls, searching, searchResult);
}