#include<stdio.h>
int binarySearch(int arr[], int size, int element_search);

int binarySearch(int arr[], int size, int element_search)
{
    int first = 0, mid, last = size - 1;
    while(first <= last)
    {
        mid = (first + last)/2;
        if(arr[mid] == element_search)
        {
            return mid;
        }
        else if(arr[mid] < element_search)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 12, 16, 18, 19, 24, 26, 29, 35, 39, 48, 57, 64, 68, 69, 72, 77, 80};
    int size = sizeof(arr)/sizeof(int);
    int element_search = 12;
    int index = binarySearch(arr, size, element_search);
    if(index == -1)
    {
        printf("Search Unsuccessful");
    }
    else
    {
        printf("Search Successful - Element is present at index %d\n", index);
    }
    return 0;
}