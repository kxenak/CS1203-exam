#include <stdio.h>
#include <stdlib.h>

void basicFizzBuzz(int x)
{
    int check = 0;
    if(x % 3 == 0 || x % 5 == 0)
    {
        printf("fizz");
        check = 1;
    }
    if(x % 11 == 0 || x % 13 == 0)
    {
        printf("buzz");
        check = 1;
    }
    if(check == 0)
        printf("%d", x);
    printf("\n");
}

int main()
{
    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);
    basicFizzBuzz(a);
    return 0;
}