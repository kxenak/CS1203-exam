#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
    struct Node *next2;
};

typedef struct Node *NodeAddress;

NodeAddress arrayTollWithNext2(int *a, int n)
{
    typedef NodeAddress node;
    node head = NULL;
    node current;
    for(int i = 0; i < n; i++)
    {
        node new = (node)malloc(sizeof(struct Node));
        new->val = a[i];
        new->next = NULL;
        new->next2 = NULL;
        if(head == NULL)
            head = new;
        else
            current->next = new;
        current = new;
    }
    node temp_head = head;
    for(int i = 1; i <= n - 2; i++)
    {
        temp_head->next2 = temp_head->next->next;
        temp_head = temp_head->next;
    }
    temp_head->next2 = NULL;
    temp_head->next->next2 = NULL;
    return head;
}

NodeAddress reverseLLWithNext2(NodeAddress head)
{
    node prev, current, next;
    node temp_head = head;
    while(current != NULL)
    {
        
    }
}

void display(NodeAddress head, int n)
{
    printf("\n");
    for(int i = 0; i < n - 2; i++)
    {
        printf("%d\n", head->next2->val);
        head = head->next;
    }
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
    NodeAddress head = arrayTollWithNext2(a, n);
    display(head, n);
    return 0;
}