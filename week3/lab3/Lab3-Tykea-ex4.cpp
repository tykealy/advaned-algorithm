#include <iostream>
using namespace std;

struct Element
{
    string Id;
    string name;
    float average;
    Element *next;
};

struct List
{
    Element *head, *tail;
    int n;
};
int check(List *ls, string ID)
{
    int match = 0;
    Element *temp;
    temp = ls->head;
    while (temp != NULL)
    {
        if (temp->Id == ID)
        {
            match = 1;
        }
        temp = temp->next;
    }
    return match;
}
List *createEmptyList()
{
    List *ls = new List;
    ls->head = NULL;
    ls->tail = NULL;
    ls->n = 0;
    return ls;
};
Element *boxInput()
{
    string ID, name;
    float avgScore;
    Element *box = new Element;
    cout << "========Adding element=========" << endl;
    cout << "Enter your ID: ";
    cin >> ID;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your average score: ";
    cin >> avgScore;
    box->name = name;
    box->Id = ID;
    box->average = avgScore;

    return box;
}
int addElementToListEnd(List *ls, Element *box)
{
    if (check(ls, box->Id))
    {
        cout << "This ID is already exist." << endl;
        return 0;
    }
    if (ls->n == 0)
    {
        box->next = NULL;
        ls->head = box;
        ls->tail = box;
    }
    else
    {
        ls->tail->next = box;
        ls->tail = box;
    }
    ls->n = ls->n + 1;
    cout << "Succesfully added." << endl;
    return 1;
}
void displayElement(List *ls)
{
    Element *temp;
    temp = ls->head;
    while (temp != NULL)
    {
        cout << "ID: " << temp->Id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Average score: " << temp->average << endl;
        cout << "=============================" << endl;
        temp = temp->next;
    }
}

int main()
{
    List *list = new List;
    int choice = -1;

    while (choice != 0)
    {
        cout << "==============Menu==============" << endl;
        cout << "1. Add citizen." << endl;
        cout << "2. Display all citizens information." << endl;
        cout << "Choose 1-3 or 0 to quit: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addElementToListEnd(list, boxInput());
            break;
        case 2:
            cout << "=========Display all informa1tions=========" << endl;
            displayElement(list);
            break;
        default:
            break;
        }
    }
}