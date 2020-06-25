#include <stdlib.h>
#include "Stack.h"

void InitializeStack(Stack *ps){

  ps->top=NULL;

  ps->size=0;
}

void Push(StackEntry e, Stack *ps){

  StackNode *pn=(StackNode*)malloc(sizeof(StackNode));

  pn->entry=e;

  pn->next=ps->top;

  ps->top=pn;

  ps->size++;

}

void Pop(StackEntry *pe, Stack *ps){

  StackNode *pn;

  *pe=ps->top->entry;

  pn=ps->top;

  ps->top=ps->top->next;

  free(pn);

  ps->size--;

}

void TraverseStack(Stack *ps, void(*pf) (StackEntry) ) {

    for (StackNode *pn = ps->top ; pn ; pn=pn->next) {

        (*pf)(pn->entry);

    }
}

int StackEmpty(Stack *ps){

	return ps->top==NULL;

}

int StackFull(Stack *ps){
	return 0;
}

int	StackSize(Stack *ps){

  int x;

  StackNode *pn=ps->top;

  for(x=0; pn; pn=pn->next)
    x++;

  return x;

}

void ClearStack(Stack *ps){

  StackNode *pn=ps->top;

  while(pn){

    pn=pn->next;

    free(ps->top);

    ps->top=pn;

  }

  ps->size=0;

}
