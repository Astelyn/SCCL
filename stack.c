#include "stack.h"

struct StackElementT {
    void*                 data;
    struct StackElementT* next;
};

struct StackT {
    struct StackElementT* top;
    unsigned              size;
};

Stack Stack_new(void)
{
    Stack stack = malloc(sizeof(struct StackT));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void Stack_free(Stack stack)
{
    struct StackElementT* curr = stack->top;
    while (curr != NULL) {
        curr = curr->next;
        free(stack->top);
        stack->top = curr;
    }

    free(stack);
}

unsigned Stack_size(Stack stack)
{
    return stack->size;
}

unsigned Stack_empty(Stack stack)
{
    return stack->size == 0;
}

void* Stack_top(Stack stack)
{
    if (stack->size == 0)
        return NULL;

    return stack->top->data;
}

void Stack_push(Stack stack, void* data)
{
    struct StackElementT* tmp = malloc(sizeof(struct StackElementT));
    tmp->data = data;
    tmp->next = stack->top;
    stack->top = tmp;
    stack->size++;
}

void* Stack_pop(Stack stack)
{
    if (stack->size == 0)
        return NULL;

    struct StackElementT* tmp = stack->top;
    void* ret = tmp->data;

    stack->top = tmp->next;
    free(tmp);

    return ret;
}

#ifdef DEBUG
int main(void)
{
    return 0;
}
#endif

