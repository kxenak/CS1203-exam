#include <stdio.h>
#include <stdlib.h>

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
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}