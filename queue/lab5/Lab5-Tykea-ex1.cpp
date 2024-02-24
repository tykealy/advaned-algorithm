#include <iostream>
#include "queue.h"

int main()
{
    Queue *q = createEmptyQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    dequeue(q);
    displayElement(q);
}