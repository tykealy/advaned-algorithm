#include <iostream>
#include <fstream>
#include <time.h>
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
void readListFromHead(List *ls)
{
    Element *tmp = ls->head;
    while (tmp != NULL)
    {
        cout << tmp->num << " ";
        tmp = tmp->next;
    }
}
void readListFromTail(List *ls)
{
    Element *tmp = ls->tail;
    while (tmp != NULL)
    {
        cout << tmp->num << " ";
        tmp = tmp->previous;
    }
}

void findMaxAndMin(List *ls, int *maxx, int *minn)
{
    Element *max = ls->head;
    Element *tmp = max->next;
    Element *min = ls->head;
    Element *tmp2 = min->next;
    while (tmp != NULL)
    {
        if (max->num < tmp->num)
        {
            max = tmp;
            tmp = tmp->next;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    while (tmp2 != NULL)
    {
        if (min->num > tmp2->num)
        {
            min = tmp2;
            tmp2 = tmp2->next;
        }
        else
        {
            tmp2 = tmp2->next;
        }
    }
    *maxx = max->num;
    *minn = min->num;
}
int findAvg(List *ls)
{
    int avg = 0;
    Element *tmp = ls->head;
    while (tmp != NULL)
    {
        avg = avg + tmp->num;
        tmp = tmp->next;
    }
    avg = avg / ls->n;
    return avg;
}
int lowerThan(List *ls)
{
    int count = 0;
    Element *tmp = ls->head;
    while (tmp != NULL)
    {
        if (tmp->num < 25)
            count++;
        tmp = tmp->next;
    }
    return count;
}

int main()
{

    int input = -1;
    int maxx = 0, minn = 0;
    srand(time(0));
    List *ls = new List;

    for (int i = 1; i <= 20; i++)
    {
        insertFromHead(ls, rand() % 100);
    }

    while (input != 0)
    {
        cout << "Enter a number to insert to DLL: ";
        cin >> input;
        if (input == 0)
            break;
        insertFromHead(ls, input);
    }
    findMaxAndMin(ls, &maxx, &minn);
    int avg = findAvg(ls);
    int lowerThan25 = lowerThan(ls);

    cout << "Average: " << avg << endl;
    cout << "Max: " << maxx << endl;
    cout << "Min: " << minn << endl;
    cout << "Lower than 25: " << lowerThan25 << endl;
    cout << "Read from head: " << endl;
    readListFromHead(ls);
    cout << "\nRead from tail: " << endl;
    readListFromTail(ls);
}