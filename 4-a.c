#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

void del_maxHeapify(int *a, int n, int i)
{
    int largest, left, right;
    largest = i;
    left = 2*i + 1;
    right = 2*i + 2;
    if(left < n && a[left] > a[largest])
        largest = left;
    if(right < n && a[right] > a[largest])
        largest = right;
    if(largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        del_maxHeapify(a, n, largest);
    }
}

void insert_maxHeapify(int *a, int n, int i)
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
    insert_maxHeapify(a, *n, *n -1);
}

int getMax_maxHeapify(int *a, int *n)
{
    int max = a[0];
    a[0] = a[*n - 1];
    *n = *n - 1;
    del_maxHeapify(a, *n, 0);
    return max;
}

void thirdLargestNum(int *maxHeap , int n)
{
    int num = 0;
    for(int i = 0; i < 3; i++)
        num = getMax_maxHeapify(maxHeap, &n);
    printf("Third largest number: %d\n", num);
}

int main()
{
    int a[MAX];
    int arr[] = {99, 50, 22, 30, 1}; // This is the test array.
    int narr = sizeof(arr)/sizeof(arr[0]);
    int n = 0;
    for(int i=0; i < narr; i++)
        insert(a, &n, arr[i]);
    printf("The heap: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    thirdLargestNum(a, n);
}