#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#ifdef DEBUG
#   include <stdio.h>
#endif

typedef struct StackT* Stack;

Stack    Stack_new   (void);
void     Stack_free  (Stack stack);
unsigned Stack_size  (Stack stack);
unsigned Stack_empty (Stack stack);
void*    Stack_top   (Stack stack);
void     Stack_push  (Stack stack, void* data);
void*    Stack_pop   (Stack stack);

#endif /* STACK_H */

