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
        ptr = ptr->next;
    }
    printf("\n");
}

// CASE 1
struct Node* insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// CASE 2
struct Node* insertInBetween(struct Node *head, int index, int data)
// Index value is the link between nodes and it starts with 1
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

// CASE 3
struct Node* insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
};

// CASE 4
struct Node* insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node *p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
};

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node*) malloc(sizeof(struct Node));
    first = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    head->data = 7;
    head->next = first;

    first->data = 10;
    first->next = second;

    second->data = 5;
    second->next = third;

    third->data = 13;
    third->next = NULL;

    // Linked List Before Insertion
    linkedListTraversal(head);
    head = insertAtFirst(head, 25);
    // Linked List After Insertion
    linkedListTraversal(head);
    head = insertInBetween(head, 3, 14);
    linkedListTraversal(head);
    head = insertAtEnd(head, 2);
    linkedListTraversal(head);
    head = insertAfterNode(head, second, 40);
    linkedListTraversal(head);
    return 0;
}