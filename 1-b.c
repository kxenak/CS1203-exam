#include <stdio.h>
#include <stdlib.h>

void advancedFizzBuzz(int *a, int m, int *b, int nb, int *f, int nf)
{
    for(int i = 0; i < m; i++)
    {
        printf("%d: ", a[i]);
        for(int j = 0; j < nf; j++)
            if(a[i] % f[j] == 0)
                printf("fizz");
        for(int j = 0; j < nb; j++)
            if(a[i] % b[j] == 0)
                printf("buzz");
        printf("\n");
    }
}

int main()
{
    int f[2] = {3, 5};
    int nf = sizeof(f)/sizeof(int);
    int b[2] = {11, 13};
    int nb = sizeof(f)/sizeof(int);
    int m;
    printf("Enter the number of elements: ");
    scanf("%d", &m);
    const int num = m;
    int a[num];
    printf("Enter the elements:\n");
    for(int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    advancedFizzBuzz(a, m, b, nb, f, nf);
    return 0;
}