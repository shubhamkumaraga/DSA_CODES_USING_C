#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void doublyLinkedListFrontTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void doublyLinkedListBackTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main()
{
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    struct Node *body1 = (struct Node*) malloc(sizeof(struct Node));
    struct Node *body2 = (struct Node*) malloc(sizeof(struct Node));
    struct Node *tail = (struct Node*) malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 10;
    head->next = body1;

    body1->prev = head;
    body1->data = 20;
    body1->next = body2;

    body2->prev = body1;
    body2->data = 30;
    body2->next = tail;

    tail->prev = tail;
    tail->data = 40;
    tail->next = NULL;

    doublyLinkedListFrontTraversal(head);
    doublyLinkedListBackTraversal(body2);

    return 0;
}