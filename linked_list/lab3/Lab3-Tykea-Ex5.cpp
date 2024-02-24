#include <iostream>

using namespace std;

struct Element
{
    string Id;
    string name;
    string gender;
    float income;
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
void Searching(List *ls)
{
    string arg;
    cout << "========Searching========" << endl;
    cout << "Enter name or ID to search: ";
    cin >> arg;
    Element *temp;
    temp = ls->head;
    while (temp != NULL)
    {
        if (arg == temp->Id || arg == temp->name)
        {
            cout << "============================" << endl;
            cout << "Citizen ID :" << temp->Id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "Monthly Income: " << temp->income << endl;
        }
        temp = temp->next;
    }
}
Element *boxInput()
{
    string Id, name, gender;
    float income;
    Element *box = new Element;
    cout << "========Adding elements=======" << endl;
    cout << "Enter your ID: ";
    cin >> Id;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your gender: ";
    cin >> gender;
    cout << "Enter your monthly income: ";
    cin >> income;

    box->Id = Id;
    box->name = name;
    box->gender = gender;
    box->income = income;

    return box;
}
int addElementToListEnd(List *ls, Element *box)
{
    if (check(ls, box->Id))
    {
        cout << "This ID is already exist." << endl;
        return 0;
    }
    else
    {
        cout << "succesfully added." << endl;
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
    return 1;
}
void displayElement(List *ls)
{
    Element *temp;
    temp = ls->head;
    while (temp != NULL)
    {
        cout << "Citizen ID :" << temp->Id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Gender: " << temp->gender << endl;
        cout << "Monthly Income: " << temp->income << endl;
        cout << "=============================" << endl;
        temp = temp->next;
    }
}
void sortCitizensBasedOnIncome(List *ls)
{
    Element *temp = ls->head;
    Element *large;
    string ID, name, gender;
    float income;
    while (temp != NULL)
    {
        large = temp->next;
        while (large != NULL)
        {
            if (temp->income < large->income)
            {

                ID = large->Id;
                income = large->income;
                name = large->name;
                gender = large->gender;

                large->gender = temp->gender;
                large->name = temp->name;
                large->income = temp->income;
                large->Id = temp->Id;

                temp->name = name;
                temp->income = income;
                temp->Id = ID;
                temp->gender = gender;
            }
            large = large->next;
        }
        temp = temp->next;
    }
}
int main()
{
    int choice = -1, n;
    List *list = new List;

    while (choice != 0)
    {
        cout << "========Menu========" << endl;
        cout << "1. Add citizen." << endl;
        cout << "2. Display all citizens information." << endl;
        cout << "3. Search for a citizens." << endl;
        cout << "4. Top 3 citizens." << endl;
        cout << "Choose 1-3 or 0 to quit: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addElementToListEnd(list, boxInput());
            break;
        case 2:
            cout << "=========Display all informations=========" << endl;
            displayElement(list);
            break;
        case 3:
            Searching(list);
            break;
        case 4:
            sortCitizensBasedOnIncome(list);
            Element *temp;
            temp = list->head;
            n = 1;
            cout << "========Top 3 citizens========" << endl;
            while (n <= 3)
            {
                cout << "Citizen ID :" << temp->Id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Gender: " << temp->gender << endl;
                cout << "Monthly Income: " << temp->income << endl;
                cout << "=============================" << endl;
                temp = temp->next;
                n++;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}