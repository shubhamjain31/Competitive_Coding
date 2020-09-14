#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize*sizeof(int));
}

void show(struct myArray *a)
{
    for(int i=0; i< a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setVar(struct myArray *a)
{
    for(int i=0; i< a->used_size; i++)
    {
        int n;
        printf("Enter elements %d: " ,i);
        scanf("\n%d",&n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myArray *marks;
    createArray(&marks, 10, 2);
    printf("We are running setVar now\n");
    setVar(&marks);
    printf("We are running show\n");
    show(&marks);
}