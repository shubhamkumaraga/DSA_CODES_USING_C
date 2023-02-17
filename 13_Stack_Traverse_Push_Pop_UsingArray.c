#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top_index;
    int *arr;
};

void stackTraverse(struct Stack *head)
{
    struct Stack *ptr = head;
    for(int i=0; i<=ptr->top_index; i++)
    {
        printf("%d ",ptr->arr[i]);
    }
    printf("\n");
}

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

void Push(struct Stack *ptr, int value)
{
    if(isFull(ptr))
        printf("Stack Overflow\n");
    else
    {
        ptr->arr[ptr->top_index + 1] = value;
        ptr->top_index++;
    }
}

int Pop(struct Stack *ptr)
{
    int temp;
    if(isEmpty(ptr))
        printf("Stack Underflow\n");
    else
    {
        temp = ptr->arr[ptr->top_index];
        ptr->top_index--;
        return temp;
    }
}

int main()
{
    struct Stack *s;
    s = (struct Stack*) malloc(sizeof(struct Stack)); // Dynamic memory allocation
    s->size = 3;
    s->top_index = -1;
    s->arr = (int*) malloc(s->size * sizeof(int));

    Push(s,2);
    stackTraverse(s);
    Push(s,5);
    stackTraverse(s);
    Push(s,25);
    stackTraverse(s);
    Push(s,15);
    stackTraverse(s);
    printf("%d\n", Pop(s));
    stackTraverse(s);
    Pop(s);
    stackTraverse(s);
    return 0;
}