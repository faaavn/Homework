#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define bool int


typedef struct tree{
    int key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
}Node;

Node *create(Node *root, int key)
{
    Node *tmp = malloc(sizeof(Node));
    tmp->key = key;
    tmp->parent = NULL;
    tmp-> left = tmp -> right = NULL;
    root = tmp;

    return root;
}


Node *add (Node *root, int key)
{
    Node *root2 = root, *root3 = NULL;
    Node *tmp = malloc(sizeof(Node));
    tmp->key=key;
    while (root2 !=NULL)
    {
        root3=root2;
        if(key < root2->key)
            root2=root2->left;
        else
            root2=root2->right;
    }
    tmp->parent = root3;
    tmp->left = NULL;
    tmp->right = NULL;
    if  (key<root3->key)
        root3->left = tmp;
    else
        root3->right = tmp;

    return root;
}

void printTree(Node *root)
{
    if(root)
    {
        printf("%d", root->key);
        if (root->left || root->right){
            printf("(");
        if (root->left)
            printTree(root->left);
        else
            printf("NULL");
        printf(",");
        if (root->right)
            printTree(root->right);
        else
            printf("NULL");
        printf(")");
        }
    }
}

int countDepth(Node *root)
{
    if(root == NULL)
        return 0;
    int left=0;
    int right=0;
    if(root->left !=NULL)
    {
        left=countDepth(root->left);
    }
    if(root->right !=NULL)
    {
        left=countDepth(root->right);
    }
    return 1 +((left>right) ? left : right);
}

bool isBalanced(Node *root)
{
    return abs(countDepth(root->left)- countDepth(root->right)) <=1;
}

void searchTree(Node *root, int *pSearch)
{
    if (root)
    {
        if(*pSearch == root->key)
        {
            printf("This is your element: ");
            printf("%2d",root->key);
            printf("\n");
        }
        else if(*pSearch < root->key)
        {
            searchTree(root->left,pSearch);
            if(root->left == *pSearch)
            {
                printf("This is your element: ");
                printf("%2d",root->left);
            }
        }
        else if(*pSearch > root->key)
        {
            searchTree(root->right,pSearch);
            if(root->right == *pSearch)
            {
                printf("This is your element: ");
                printf("%2d",root->right);
            }
        }
    }
    else
    {
        printf("Your element is not here");
    }
}

int balancedPercent(Node *root)
{
    const int TREES = 50;
    const int size = 10000;
    int balanced =0;
    for(int i=0; i < TREES; ++i)
    {
        Node *root = NULL;
        root=create(root,rand()%1000);
        for( int j =0; j < size; j++)
        {
            root=add(root, rand()%1000);
        }
        balanced += isBalanced(root) ? 1 : 0;
    }
    printf("The percentage of Balanced trees: ");

    printf("%d%%\n", balanced * 100/TREES);
}

int main()
{
    //=======================================1st=====================
    Node *root = NULL;

    srand(time(NULL));
    root=create(root,rand()%100);
    root=add(root,rand()%100);
    root=add(root,rand()%100);
    root=add(root,rand()%100);
    root=add(root,rand()%100);
    root=add(root,rand()%100);
    root=add(root,rand()%100);
    root=add(root,rand()%100);
    printTree(root);
    printf("\n");


    if (isBalanced(root))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");
     printf("\n");

    balancedPercent(root);

    //=======================================2nd=====================

    printf("Type the number u want to find: ");
    int element =0;
    scanf("%d", &element);
    printf("\n");
    int *pSearch;
    *pSearch = element;
    searchTree(root,pSearch);

    return 0;
}
