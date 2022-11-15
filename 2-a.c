#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
    struct Node *next2;
};

typedef struct Node *node;
typedef node NodeAddress;
node Head = NULL;
node current = NULL;

void insert(int data)
{
    node new = (node)malloc(sizeof(struct Node));
    new->val = data;
    new->next = NULL;
    new->next2 = NULL;
    if(Head == NULL)
        Head = new;
    else
        current->next = new;
    current = new;
}

NodeAddress arrayTollWithNext2(int *a, int n)
{
    node head = NULL;
    for(int i = 0; i < n; i++)
    {
        insert(a[i]);
    }
    return head;
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    const int num = n;
    int a[num];
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    arrayTollWithNext2(a, n);
    return 0;
}