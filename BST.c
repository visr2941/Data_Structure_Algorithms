#include <stdio.h>
#include <malloc.h>

/* structure of a bst node*/
typedef struct bst_node { 
    int data;
    struct bst_node * left;
    struct bst_node * right;

} bst_node;

/* to insert root node, or any leaf in the bst */
void insert(bst_node** root, int data)
{
    // if the BST is empty, add the root node
    if(*root == NULL)
    {
        *root = (bst_node *) malloc(sizeof(bst_node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    /* if root node is already present, compare the data 
       and insert on left if smaller and on right if larger */ 
    else if(data < (*root)->data)
        insert(&((*root)->left), data);
    else if(data >= (*root)->data)
        insert(&((*root)->right), data);
        
    return;
}

/* search a node with the data input */
bst_node** search(bst_node ** root, int data)
{
    // if the BST is empty, return NULL
    if(*root == NULL || root == NULL)
        return NULL;
    /* BST not empty, compare the data and call the function
       recursively until data found */
    else if((*root)->data == data)
        return root;
    else if((*root)->data > data)
        return search(&(*root)->left, data);
    else if((*root)->data < data)
       return search(&(*root)->right, data);
}

/* fucntion to find the lowest in BST */
bst_node ** findLowest(bst_node ** root)
{
    // passing invalid pointers or BST empty
    if(*root == NULL || root == NULL)
        return NULL;
    // find the lowest recursively
    else if((*root)->left != NULL)
        root = findLowest(&((*root)->left));
    else
        return root;
}

/* function to delete the node with the given data */
void delete (bst_node ** root, int data)
{
    // passing invalid pointers or BST empty
    if(root == NULL || *root == NULL)
        return;
    
    // look for the node to be deleted
    bst_node ** nodeDeleted = search(root, data);
    
    // if the node is leaf node, simply delete it
    if((*nodeDeleted)->left == NULL && (*nodeDeleted)->right == NULL)
    {   
        free(*nodeDeleted);
        *nodeDeleted = NULL;
    }
    /* if the node has a sub-tree on right (nothing on left)
    ** delete the node and attach the right sub-tree to the main 
    ** tree. Samething will happen if nothing is present on left
    ** but there is sub-tree on right
    */
    else if ((*nodeDeleted)->left == NULL)
    {
        free(*nodeDeleted);
        *nodeDeleted = (*nodeDeleted)-> right;
    }
    else if ((*nodeDeleted)->right == NULL)
    {
        free(*nodeDeleted);
        *nodeDeleted = (*nodeDeleted)-> left;
    }
    /* if the node to be deleted has both right and left sub-tree,
    go to the right sub-tree and find the lowest value node. Replace
    data of the node to be deleted with this lowest value, and delete
    the lowest value node */
    else
    {
       bst_node ** temp = findLowest(&((*nodeDeleted)->right));
       (*nodeDeleted)->data = (*temp)->data;
       delete (temp, (*temp)->data);
    }
        
}

/* function to initialize a BST */
void initialize_bst(bst_node** root, int data)
{
    if(*root != NULL)
    {
        *root = (bst_node *) malloc(sizeof(bst_node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
        printf("BST is already initialized");
}

/* search code without recursion */
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
   
    initialize_bst(&root, 10);
    insert(&root, 10);
    insert(&root, 7);
    insert(&root, 15);
    insert(&root, 11);
    insert(&root, 8);
    insert(&root, 9);
    insert(&root, 18);
    insert(&root, 17);
    
    bst_node** searchfound = search(&root, 15);
    if(searchfound) 
        if(*searchfound) {
            printf("Hello World %d\n", (*searchfound)->data);
            printf("Hello World %d\n", (*searchfound)->right->data);   
        }
        else
            printf("Not found");
    else
        printf("Not found");  
        
    delete (&root, 15);
    
    searchfound = search(&root, 100);
    
    if(searchfound) 
        if(*searchfound) {
            printf("Hello World %d\n", (*searchfound)->data);
            printf("Hello World %d\n", (*searchfound)->right->data);   
        }
        else
            printf("Not found");
    else
        printf("Not found");      
    

    return 0;
}
