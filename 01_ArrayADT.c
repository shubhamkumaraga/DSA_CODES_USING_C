#include<stdio.h>
#include<stdlib.h>

struct myArray // abstract data type
{
    int array_size;
    int size_utilized;
    int *ptr;    
};

void createArray(struct myArray *a, int aSize, int uSize)
{
    // (*a).array_size = aSize;
    // (*a).size_utilized = uSize;
    // (*a).ptr = (int*) malloc(aSize*sizeof(int));
    a->array_size = aSize;
    a->size_utilized = uSize;
    a->ptr = (int *) malloc(aSize*sizeof(int));
}

void show(struct myArray *a)
{
    printf("The values stored in the array are:\n");
    for(int i=0; i<a->size_utilized; i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}

void setValue(struct myArray *a)
{
    int n;
    for(int i=0; i<a->size_utilized; i++)
    {
        printf("Enter element %d: ",i);
        scanf("%d",&n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    setValue(&marks);
    show(&marks);
    return 0;
}