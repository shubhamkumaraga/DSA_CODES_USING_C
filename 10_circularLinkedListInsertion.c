#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void circularLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");    
}

struct Node* circularLinkedListInsertionAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node *p = head->next;
    ptr->data = data;
    do
    {
        p = p->next;
    } while (p->next != head);
    // p points to the last node of the circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node* circularLinkedListInsertionAtIndex(struct Node *head, int index, int data)
{
    struct Node *p = (struct Node*) malloc(sizeof(struct Node));
    struct Node *ptr = head;
    while((index-1) != 0)
    {
        ptr = ptr->next;
        index -= 1;
    }
    p->data = data;
    p->next = ptr->next;
    ptr->next = p;
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
    sixth->next = head;

    // Circular Linked List before Insertion
    circularLinkedListTraversal(head);
    // Circular Linked List after Insertion
    head = circularLinkedListInsertionAtFirst(head, 1);
    circularLinkedListTraversal(head);
    head = circularLinkedListInsertionAtIndex(head, 2, 25);
    circularLinkedListTraversal(head);
    return 0;
}