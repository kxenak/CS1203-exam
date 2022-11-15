#include <stdio.h>
#include <stdlib.h>

void advancedFizzBuzz(int *a, int m, int *b, int nb, int *f, int nf)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < nf; j++)
            for(int k = 0; k < nb; k++)
                if(a[i] % f[j] == 0 && a[i] % b[k] == 0)
                    printf("%d: fizzbuzz\n", a[i]);
                else if(a[i] % b[k] == 0)
                    printf("%d: buzz\n", a[i]);
                else if(a[i] % f[j] == 0)
                    printf("%d: fizz\n", a[i]);
                else
                    printf("%d: NA\n", a[i]);
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