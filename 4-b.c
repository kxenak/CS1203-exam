#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 1000

void insert_Heapify(int *a, int n, int i)
{
    int parent = (i - 1)/2;
    while(i > 0)
    {
        if (a[parent] < a[i])
        {
            int temp = a[parent];
            a[parent] = a[i];
            a[i] = temp;
        }
        i = parent;    
        if (a[parent] < a[i])
        {
            int temp = a[parent];
            a[parent] = a[i];
            a[i] = temp;
        }
        parent = (i -1 )/2;
    }
}

void insert(int *a, int *n, int val)
{
    int i;
    if(*n == MAX)
    {
        printf("FULL HEAP\n");
        return;
    }
    (*n)++;
    a[*n - 1] = val;
    insert_Heapify(a, *n, *n -1);
}

void returnSmallestNum(int* maxHeap, int n)
{
    int smallest = INT_MAX;
    for(int i = n/2; i < n; i++)
    {
        if(smallest < maxHeap[i])
            smallest = smallest;
        else
            smallest = maxHeap[i];
    }
    printf("Smallest element: %d\n", smallest);
}

int main()
{
    int a[MAX];
    int arr[] = {99, 50, 22, 30, 4, 3, 2}; // This is the test array.
    int narr = sizeof(arr)/sizeof(arr[0]);
    int n = 0;
    for(int i=0; i < narr; i++)
        insert(a, &n, arr[i]);
    printf("The heap: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    returnSmallestNum(a, n);
}