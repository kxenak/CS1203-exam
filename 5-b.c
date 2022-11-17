#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* sortEveryThirdElement(int *a, int n)
{
    int temp;
    for(int i = 0; i < n; i += 3)
        for(int j = i + 3; j < n; j += 3)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    return a;
}

void kSmallestAmongUntouched(int *a, int k, int n)
{
    int temp = INT_MIN;
    int temp1 = INT_MAX;
    int num = n - (n / 3);
    for(int i = 0; i < k && i < num; i ++)
    {
        for(int j = 1; j < n; j++)
            if(j % 3 != 0)
                if(temp1 > a[j] && a[j] > temp)
                    temp1 = a[j];
        temp = temp1;
        temp1 = INT_MAX;
        printf("%d\n", temp);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a = sortEveryThirdElement(a, n);
    printf("Soreted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("k smallest elements:\n");
    int k = 3;
    kSmallestAmongUntouched(a, k, n);
    return 0;
}