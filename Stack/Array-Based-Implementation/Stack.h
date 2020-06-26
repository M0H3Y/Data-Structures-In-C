typedef char StackEntry;  // the default type of StackEntry
#define MAXSTACK 100      // the default maximum number of elements in the stack

typedef struct stack{
  int top;
  StackEntry entry[MAXSTACK];
} Stack;

void  InitializeStack(Stack *);
void  Push  (StackEntry, Stack *);
void  Pop  (StackEntry *, Stack *);
int  StackEmpty  (Stack *);
int  StackFull  (Stack *);
void  StackTop  (StackEntry *, Stack *);
int  StackSize  (Stack *);
void  ClearStack(Stack *);
void  TraverseStack(Stack *, void (*)(StackEntry));
