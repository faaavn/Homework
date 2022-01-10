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

bool isBalanced(Node *root)
{
    if (root == NULL)
    return 1;

  int lh = isBalanced(root->left);
  int rh = isBalanced(root->right);

  if (abs(lh - rh) <= 1)
    return 0;
  else
    return 1;
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
int main()
{
    //=======================================1st=====================
    Node *root = NULL;

    srand(time(NULL));
    root=create(root,rand()%1000);
    root=add(root,rand()%1000);
    root=add(root,rand()%1000);
    root=add(root,rand()%1000);
    root=add(root,rand()%1000);
    root=add(root,rand()%1000);
    root=add(root,rand()%1000);
    root=add(root,rand()%1000);
    printTree(root);
    printf("\n");

    /*for(int i = 0; i <= 50; i++) запутался с заданием посторения 50 деревьев, не совсем понял как это реализовывать
    {                              посмотрю на вебинаре, как вы это записали
        root = create(root,rand());

        for(int j = 0; j <= 10000; j++)
        {
           root = add (root,rand());
        }
    }
       printf("\n");*/

    if (isBalanced(root))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");
     printf("\n");
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
