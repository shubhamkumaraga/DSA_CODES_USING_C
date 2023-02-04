#include<stdio.h>
void linearSearch(int arr[], int size, int element_search);

void linearSearch(int arr[], int size, int element_search)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==element_search)
        {
            printf("Search Successful - ");
            printf("Element is present at index %d\n", i);
            return;
        }
    }
    printf("Search Unsuccessful");
}

int main()
{
    int arr[] = {12, 26, 38, 44, 18, 69, 30, 21, 28, 20, 35, 40, 22, 46, 88, 54, 58, 79, 60, 55};
    // Array_Size = sizeof(arr)/sizeof(int);
    linearSearch(arr, 20, 40);
    linearSearch(arr, 20, 10);
    return 0;
}