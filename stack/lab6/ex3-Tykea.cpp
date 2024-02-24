#include <iostream>
using namespace std;

struct Node
{
    char parentheses;
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

void push(Stack *newStack, char userParentheses)
{
    Node *newNode = new Node;

    newNode->parentheses = userParentheses;

    if (newStack->index == 0)
        newNode->next = NULL;
    if (newStack->index != 0)
        newNode->next = newStack->top;

    newStack->top = newNode;
    newStack->index += 1;
}

void pop(Stack *newStack)
{
    Node *tempNode = newStack->top;

    if (newStack->index == 0)
    {
        cout << "There is no data." << endl;
        return;
    }

    newStack->top = newStack->top->next;
    newStack->index -= 1;

    delete tempNode;
}

char peek(Stack *newStack)
{
    Node *tempNode = newStack->top;

    if (newStack->index != 0)
    {
        return tempNode->parentheses;
    }

    return 0;
}

void checkParentheses(Stack *newStack, string userParentheses)
{
    for (int i = 0; i < userParentheses.length(); i++)
    {
        if (userParentheses[i] == '(' || userParentheses[i] == '[' || userParentheses[i] == '{')
        {
            push(newStack, userParentheses[i]);
            continue;
        }
        else if (peek(newStack) == '(' && userParentheses[i] == ')')
        {
            pop(newStack);
            continue;
        }
        else if (peek(newStack) == '[' && userParentheses[i] == ']')
        {
            pop(newStack);
            continue;
        }
        else if (peek(newStack) == '{' && userParentheses[i] == '}')
        {
            pop(newStack);
            continue;
        }
    }

    if (newStack->index == 0)
    {
        cout << "The parentheses is balancing." << endl;
        return;
    }
    else
    {
        cout << "The parentheses is not balancing." << endl;
        return;
    }
}

int main()
{
    string userParentheses;

    Stack *stack1 = createEmptyStack();

    cout << "Please input ( ) [ ] { } to check whether it's balanced or not : ";
    cin >> userParentheses;

    checkParentheses(stack1, userParentheses);

    return 0;
}