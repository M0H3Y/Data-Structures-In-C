#include "Stack.h"

void InitializeStack(Stack *ps){
    ps->top=0;
}

void Push(StackEntry e, Stack *ps) {
    ps-> entry[ps->top++] = e;
}

void Pop(StackEntry *pe,Stack *ps) {
    *pe = ps->entry[--ps->top];
}
void StackTop(StackEntry *pe, Stack *ps){
	*pe=ps->entry[ps->top-1];
}
void TraverseStack(Stack *ps, void(*pf)(StackEntry)){
   for(int i=ps->top; i>0; i--)
      (*pf)(ps->entry[i-1]);
}
int StackFull(Stack *ps) {
    return ps->top >= MAXSTACK;
}

int StackEmpty(Stack *ps) {
    return !ps->top;
}
int StackSize(Stack *ps){
   return ps->top;
}
void ClearStack(Stack *ps){
   ps->top=0;
}
