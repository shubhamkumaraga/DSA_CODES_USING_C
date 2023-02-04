#include<stdio.h>
void display(int arr[], int size); // Traversal of an array
int indexDeletion(int arr[], int size, int index);

void display(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indexDeletion(int arr[], int size, int index)
{
    if(index>size)
    {
        printf("Deletion Failed\n");
        return -1;
    }
    else
    {
        for(int i=index; i<size-1; i++)
        {
            arr[i] = arr[i+1];
        }
        arr[size-1] = 0;
        printf("Deletion Succcessful ");
        display(arr, size-1);
        return 0;
    }
}

int main()
{
    int arr[100] = {4, 5, 2, 8, 14, 6, 24};
    int size = 7, index = 1;
    display(arr, size);
    indexDeletion(arr, size, index);
    size -= 1;
    indexDeletion(arr, size, 0);
    size -= 1;
    indexDeletion(arr, size, 10);
    return 0;
}