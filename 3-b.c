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

void successorReverseBST(node root, int k)
{
    if(root == NULL)
    {
        printf("Pudding\n");
        return;
    }
    if(root->key == k)
    {
        if(root->right != NULL)
        {
            node temp = root->right;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            printf("%d", temp->key);
        }
        else
        {
            printf("Hamburger");
        }
        return;
    }
    else if(k < root->key)
    {
        successorReverseBST(root->left, k);
    }
    else
    {
        successorReverseBST(root->right, k);
    }
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
    int k;
    printf("Enter the key: ");
    scanf("%d", &k);
    printf("Successor: ");
    successorReverseBST(root, k);
    return 0;
}