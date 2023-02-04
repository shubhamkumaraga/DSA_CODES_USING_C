#include<stdio.h>
void display(int arr[], int n); // Traversal of an array
int indexInsertion(int arr[], int size, int element_insert, int capacity, int index);

void display(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indexInsertion(int arr[], int size, int element_insert, int capacity, int index)
{
    if(size>=capacity || index>size)
    {
        printf("Insertion Failed\n");
        return -1;
    }
    else
    {
        for(int i=size; i>index; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[index] = element_insert;
        printf("Insertion Successful ");
        display(arr, size+1);
        return 0;
    }
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element_insert = 45, capacity = 100, index = 3;
    display(arr, size);
    indexInsertion(arr, size, element_insert, capacity, index);
    size += 1;
    indexInsertion(arr, size, 21, capacity, 1);
    size += 1;
    indexInsertion(arr, size, 54, capacity, 7);
    size += 1;
    indexInsertion(arr, size, 10, capacity, 15);
    return 0;
}