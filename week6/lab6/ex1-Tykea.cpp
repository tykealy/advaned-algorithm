#include "stack.h"

int main()
{
    Stack *st = createEmptyStack();

    push(st, 9);
    push(st, 10);

    displayElement(st);
}