#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
    int k;
    struct Node *nextk;
};

typedef struct Node *NodeAddress;

NodeAddress arrayTollWithNextK(int *a, int n)
{
    typedef NodeAddress node;
    node head = NULL;
    node current;
    for(int i = 0; i < n; i++)
    {
        node new = (node)malloc(sizeof(struct Node));
        new->val = a[i];
        new->next = NULL;
        new->k = (rand() + 2) % 5;
        new->nextk = NULL;
        if(head == NULL)
            head = new;
        else
            current->next = new;
        current = new;
    }
    node temp_head = head;
    node temp;
    for(int i = 0; i < n; i++)
    {
        temp = temp_head;
        for(int j = 0; j < temp_head->k; j++)
        {
            if(temp->next == NULL)
            {
                temp_head->nextk = NULL;
                goto there;
            }
            else
                temp = temp->next;
        }
        temp_head->nextk = temp;
        there:
        temp_head = temp_head->next;
    }
    return head;
}

//reverse this linked list

NodeAddress reverseLLWithNextK(NodeAddress head)
{
    typedef NodeAddress node;
    node prev = NULL;
    node current = head;
    node next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    node temp_head = head;
    node temp;
    while(temp_head != NULL)
    {
        temp = temp_head;
        for(int j = 0; j < temp_head->k; j++)
        {
            if(temp->next == NULL)
            {
                temp_head->nextk = NULL;
                goto there;
            }
            else
                temp = temp->next;
        }
        temp_head->nextk = temp;
        there:
        temp_head = temp_head->next;
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
    NodeAddress head = arrayTollWithNextK(a, n);
    display(head, n);
    return 0;
}