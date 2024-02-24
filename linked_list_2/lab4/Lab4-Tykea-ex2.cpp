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

void inserFromHead(List *ls, int num)
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

void WriteListToFile(List *ls)
{
    fstream outputFile;
    outputFile.open("Output-Ex2-Tykea.txt", ios::app);
    Element *tmp = ls->head;

    while (tmp != NULL)
    {
        outputFile << tmp->num << endl;
        tmp = tmp->next;
    }
    outputFile.close();
}

int main()
{
    int n;
    List *list = createEmptyList();

    inserFromHead(list, 1);
    inserFromHead(list, 2);
    inserFromHead(list, 3);
    inserFromHead(list, 5);
    inserFromHead(list, 0);
    inserFromHead(list, -1);

    cout << "Enter n to DLL: ";
    cin >> n;

    inserFromHead(list, n);
    WriteListToFile(list);
}