#include<stdlib.h>
#include<stdio.h>

int prim (int num)
{
    for (int i=2; i<=num/2; i++)
    {
        if (num%i == 0) return 0;
    }
    return 1;
}

int sumNumPrim(int num)
{
    int sum = 0;
    for (int i=2; i<=num/2; i++)
    {
        if (prim(i) && prim(num - i))
        {
            sum++;
        }
    }
    if (sum == 2) return 1; else return 0;
}

void main()
{
    int n, *arr;
    int size = 0;
    scanf("%d",&n);

    arr = (int*)malloc(sizeof(int));
    for (int i=2; i<n; i++)
    {
        if (sumNumPrim(i))
        {
            arr[size] = i;
            size++;
            arr = realloc(arr, (size+1)*sizeof(int));
        }
    }

    for (int i =0; i<size; i++)
    {
        printf(" %d ",arr[i]);
    }

    free(arr);
}