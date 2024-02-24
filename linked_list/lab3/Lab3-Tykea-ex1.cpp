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

int main();