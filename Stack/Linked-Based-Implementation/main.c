#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void display(StackEntry e) {
    printf("e is : %d \n", e);
}

int main()
{
    Stack s;

    InitializeStack(&s);

    Push(5,&s);

    Push(6,&s);

    Push(8,&s);

    TraverseStack(&s,&display);


    return 0;
}
