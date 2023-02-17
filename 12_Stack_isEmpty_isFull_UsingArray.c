#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top_index;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if(ptr->top_index == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *ptr)
{
    if(ptr->size-1 == ptr->top_index)
    {
        return 1;
    }
    return 0;
}

int main()
{
    struct Stack *s;
    s = (struct Stack*) malloc(sizeof(struct Stack));
    s->size = 20;
    s->top_index = -1; // Stack is empty
    s->arr = (int *) malloc(s->size * sizeof(int));

    s->arr[0] = 5;
    s->top_index++;
    s->arr[1] = 10;
    s->top_index++;

    if(isEmpty(s))
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");

    if(isFull(s))
        printf("Stack is full\n");
    else
        printf("Stack is not full\n");

    return 0;
}