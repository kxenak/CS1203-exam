#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

typedef struct node *NodeAddress;
typedef NodeAddress node;

node insert(node root, int key)
{
    if(root == NULL)
    {
        root = (node)malloc(sizeof(struct node));
        root->key = key;
        root->left = NULL;
        root->right = NULL;
    }
    else if(key >= root->key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

void prefixPrint(NodeAddress root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        prefixPrint(root->left);
        prefixPrint(root->right);
    }
}

NodeAddress arrayToReverseBST(int *a, int n)
{
    node root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, a[i]);
    }
    printf("Preorder: ");
    prefixPrint(root);
    printf("\n");
    return root;
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    const int size = n;
    int a[size];
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    node root = NULL;
    root = arrayToReverseBST(a, n);
    return 0;
}