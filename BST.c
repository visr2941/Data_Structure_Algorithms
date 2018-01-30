#include <stdio.h>
#include <malloc.h>

typedef struct bst_node { 
    int data;
    struct bst_node * left;
    struct bst_node * right;

} bst_node;

void insert(bst_node** root, int data)
{
    if(*root == NULL)
    {
        *root = (bst_node *) malloc(sizeof(bst_node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    else if(data < (*root)->data)
        insert(&((*root)->left), data);
    else if(data >= (*root)->data)
        insert(&((*root)->right), data);
        
    return;
}

bst_node * search(bst_node ** root, int data)
{
    if(*root == NULL || (*root)->data == data)
        return *root;
    else if((*root)->data > data)
        return search(&(*root)->left, data);
    else if((*root)->data < data)
       return search(&(*root)->right, data);
}

//searching without recursion
/*bst_node * search(bst_node ** root, int data)
{
    bst_node * rtnPtr = *root;

    while(rtnPtr != NULL)
    {
        if(rtnPtr->data != data)
        {
            if(rtnPtr->data < data)
            {
                rtnPtr = rtnPtr->right;
            }
            else
                rtnPtr = rtnPtr->left;
        }
        else
            return rtnPtr;
    }
    return rtnPtr;
}*/

int main()
{
    bst_node* root = NULL;
    insert(&root, 10);
    insert(&root, 7);
    insert(&root, 15);
    insert(&root, 11);
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 15);
    
    bst_node * searchfound = search(&root, 11);
    
    if(searchfound) {
        printf("Hello World %d\n", searchfound->data);
        printf("Hello World %d\n", searchfound->right->data);    
        
    }
    else
        printf("Not found");    

    return 0;
}


