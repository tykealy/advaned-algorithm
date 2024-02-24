#include <iostream>
#include <math.h>
using namespace std;
struct checkResult
{
    bool state;
    int index;
} result;
struct Element
{
    int Data;
    Element *next;
};
struct List
{
    int n;
    Element *head, *tail;
};

const int SIZE = 7;
List *table[SIZE];

int hashFunction(int data)
{
    return floor(data % SIZE);
}

List *createList()
{
    List *ls = new List;
    ls->n = 0;
    ls->head = NULL;
    ls->tail = NULL;
    return ls;
}
void createLists()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = createList();
    }
}
void addToEnd(int data, int index)
{
    Element *e = new Element;
    e->Data = data;
    e->next = NULL;
    if (table[index]->n == 0)
    {
        table[index]->head = e;
        table[index]->tail = e;
    }
    else
    {
        table[index]->tail->next = e;
        table[index]->tail = e;
    }
    table[index]->n = table[index]->n + 1;
}
void insert(int data)
{
    int index = hashFunction(data);
    addToEnd(data, index);
}
void displayTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        Element *tmp = table[i]->head;
        cout << i << "\t";
        while (tmp != NULL)
        {
            cout << tmp->Data << "  ";
            tmp = tmp->next;
        }
        cout << "\n";
    }
}
void check(int data)
{
    int index = hashFunction(data);
    result.state = false;q
    Element *tmp = table[index]->head;
    while (tmp != NULL)
    {
        if (tmp->Data == data)
        {
            result.state = true;
            result.index = index;
            break;
        }
        tmp = tmp->next;
    }
}
void search(int data)
{
    check(data);
    if (result.state)
    {
        cout << data << " is exist at index " << result.index << endl;
    }
    else
    {
        cout << "Not found." << endl;
    }
}
void removeFromTable(int data)
{
    check(data);
    int index = result.index;
    if (result.state)
    {
        Element *tmp = table[index]->head;
        while (tmp != NULL)
        {
            if (tmp->Data == data)
            {
                tmp->Data = 0;
                cout << "Removed successfully." << endl;
                break;
            }
            tmp = tmp->next;
        }
    }
    else
    {
        cout << "Failed to remove " << data << " as it does not exist." << endl;
    }
}

int main()
{
    createLists();
    insert(2);
    insert(4);
    insert(7);
    insert(10);
    search(7);
    removeFromTable(10);
    displayTable();
}