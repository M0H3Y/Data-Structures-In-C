typedef char StackEntry;  // the default type of StackEntry

typedef struct stacknode {
    StackEntry entry;

    struct stacknode *next;

} StackNode;

typedef struct stack {
    StackNode *top;

    int	size;

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
