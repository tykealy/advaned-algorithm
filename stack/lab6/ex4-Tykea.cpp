#include <iostream>
using namespace std;

struct Node
{
    int bin;
    Node *next;
};

struct Stack
{
    int index;
    Node *top;
};

Stack *createEmptyStack()
{
    Stack *newStack = new Stack();

    newStack->index = 0;
    newStack->top = NULL;

    return newStack;
};

void push(Stack *newStack, int userBin)
{
    Node *newNode = new Node();

    newNode->bin = userBin;

    if (newStack->index == 0)
        newNode->next = NULL;
    if (newStack->index != 0)
        newNode->next = newStack->top;

    newStack->top = newNode;
    newStack->index += 1;
}

void displayStack(Stack *newStack)
{
    Node *tempNode = newStack->top;

    if (tempNode == NULL)
    {
        cout << "There is no data" << endl;
        return;
    }
    while (tempNode != NULL)
    {
        cout << tempNode->bin;
        tempNode = tempNode->next;
    }
}

void binConverter(Stack *newStack, int userInt)
{
    int remainder;
    while (userInt > 0)
    {
        remainder = userInt % 2;
        userInt /= 2;
        push(newStack, remainder);
    }
}

int main()
{
    int userInt;

    Stack *stack1 = createEmptyStack();

    cout << "Please enter positive integer : ";
    cin >> userInt;

    binConverter(stack1, userInt);

    cout << userInt << " = ";

    displayStack(stack1);
    cout << " in binary" << endl;

    return 0;
}
