#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr =  ptr->next;
    }
    printf("\n");
}

// CASE 1
struct Node* deletionAtFirst(struct Node *head)
{
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;

}

// CASE 2
struct Node* deletionInBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(index != 1)
    {
        p = p->next;
        q = q->next;
        index -= 1;
    }
    p->next = q->next;
    free(q);
    return head;
}

// CASE 3
struct Node* deletionAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// CASE 4
struct Node* deletionByValue(struct Node *head, int value)
{
    struct Node *p = head;
    if(head->data == value)
    {
        head = deletionAtFirst(head);
        return head;
    }
    struct Node *q = head->next;
    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));
    fifth = (struct Node*) malloc(sizeof(struct Node));
    sixth = (struct Node*) malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 5;
    third->next = fourth;

    fourth->data = 12;
    fourth->next = fifth;

    fifth->data = 7;
    fifth->next = sixth;

    sixth->data = 15;
    sixth->next = NULL;

    // Linked List Before Deletion
    linkedListTraversal(head);
    // Linked List After Deletion
    head = deletionAtFirst(head);
    linkedListTraversal(head);
    head = deletionInBetween(head, 1);
    linkedListTraversal(head);
    head = deletionAtEnd(head);
    linkedListTraversal(head);
    head = deletionByValue(head, 8);
    linkedListTraversal(head);
    return 0;
}