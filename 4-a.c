// Implemention of a heap.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void maxheapify(int *a, int i, int n)
{
    int l = 2*i;
    int r = 2*i+1;
    int largest;
    if(l <= n && a[l] > a[i])
        largest = l;
    else
        largest = i;
    if(r <= n && a[r] > a[largest])
        largest = r;
    if(largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        maxheapify(a, largest, n);
    }
}

int buildmaxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
        maxheapify(a, i, n);
}

void heapsort(int *a, int n)
{
    for(int i = n; i >= 2; i--)
    {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        n--;
        maxheapify(a, 1, n);
    }
}

void thirdLargestNum(int *maxHeap, int n)
{
    heapsort(maxHeap, n);
    printf("Third largest number: %d\n", maxHeap[n-2]);
}

int main()
{
    int a[MAX];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    buildmaxheap(a, n);
    thirdLargestNum(a, n);
    return 0;
}