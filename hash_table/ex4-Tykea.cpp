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
    string id;
    string name;
    char sex;
    string phone;
    Element *next;
};
struct List
{
    int n;
    Element *head, *tail;
};

const int SIZE = 10;
List *table[SIZE];

int hashFunction(string id)
{
    int dec = 0;
    for (int i = 0; i < id.length(); i++)
    {

        dec += int(id[i]);
    }
    return dec % SIZE;
    // return floor(data % SIZE);
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
void addToEnd(int index, string id, string name, char sex, string phone)
{
    Element *e = new Element;
    e->id = id;
    e->name = name;
    e->sex = sex;
    e->phone = phone;
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
void insert(string id, string name, char sex, string phone)
{
    int index = hashFunction(id);
    addToEnd(index, id, name, sex, phone);
}
void displayTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        Element *tmp = table[i]->head;
        cout << i << "\t";
        while (tmp != NULL)
        {
            cout << tmp->id << ", ";
            cout << tmp->name << ", ";
            cout << tmp->sex << ", ";
            cout << tmp->phone << " || ";
            tmp = tmp->next;
        }
        cout << "\n";
    }
}
void check(string id)
{
    int index = hashFunction(id);
    result.state = false;
    Element *tmp = table[index]->head;
    while (tmp != NULL)
    {
        if (tmp->id == id)
        {
            result.state = true;
            result.index = index;
            break;
        }
        tmp = tmp->next;
    }
}
void search(string id)
{
    check(id);
    if (result.state)
    {
        cout << id << " is exist at index " << result.index << endl;
    }
    else
    {
        cout << "Not found." << endl;
    }
}
void removeFromTable(string data)
{
    check(data);
    int index = result.index;
    if (result.state)
    {
        Element *tmp = table[index]->head;
        while (tmp != NULL)
        {
            if (tmp->id == data)
            {
                tmp->id = "";
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
    insert("IDTB080029", "tykea", 'm', "0962200288");
    insert("IDTB080029", "tk", 'm', "0962200299");
    insert("IDTB080028", "bruh", 'm', "030233223");

    displayTable();
}