
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int ele;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *create_node(int);
void insert(int);
struct node *delete (struct node *, int);
int search(int);
void inorder(struct node *);
void postorder();
void preorder();
int read_data();
 
int main()
{
    int ch;
    int ele;
    struct node* result = NULL;
    while(ch != 8)
    {
        printf("\nMENU:\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
  printf("\n4. Inorder ");
        printf("\n5. Post Order ");
        printf("\n6. Pre Oder ");
        printf("\n7. Exit");
 
        printf("enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                ele = read_data();
                insert(ele);
                break;
 
            case 2:
                ele = read_data();
                root = delete(root, ele);
                break;
 
            case 3:
                ele = read_data();
                if (search(ele) == 1)
                {
                    printf("element found!\n");
                }
                else
                {
                    printf("element not found!\n");
                }
                break;
 
            case 4:
                inorder(root);
                break;
 
            case 5:
                postorder(root);
                break;
 
            case 6:
                preorder(root);
                break;
 
            case 7:
                exit(1);
                break;
 
            default:
                printf("enter valid choice!\n");
                break;
        }
 
       
    }
 
    return 0;
}
 
// creates a new node
struct node *create_node(int ele)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
 
    if (new_node == NULL)
    {
        printf("\nMemory for new node can't be allocated");
        return NULL;
    }
 
    new_node->ele = ele;
    new_node->left = NULL;
    new_node->right = NULL;
 
    return new_node;
}
 
// inserts the data in the BST
void insert(int ele)
{
    struct node *new_node = create_node(ele);
 
    if (new_node != NULL)
    {
        // if the root is empty then make a new node as the root node
        if (root == NULL)
        {
            root = new_node;
            printf("\n* node having data %d was inserted\n", ele);
            return;
        }
 
        struct node *temp = root;
        struct node *prev = NULL;
 
        // traverse through the BST to get the correct position for insertion
        while (temp != NULL)
        {
            prev = temp;
            if (ele > temp->ele)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
 
        // found the last node where the new node should insert
        if (ele > prev->ele)
        {
            prev->right = new_node;
        }
        else
        {
            prev->left = new_node;
        }
 
        printf("\n* node having data %d was inserted\n", ele);
    }
}
 
// deletes the given key node from the BST
struct node *delete (struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->ele)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->ele)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
    }
    return root;
 
}
 
// search the given key node in BST
int search(int key)
{
    struct node *temp = root;
 
    while (temp != NULL)
    {
        if (key == temp->ele)
        {
            return 1;
        }
        else if (key > temp->ele)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return 0;
}

// inorder traversal of the BST
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",  root->ele);
    inorder(root->right);
}
 
// preorder traversal of the BST
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->ele);
    preorder(root->left);
    preorder(root->right);
}
 
// postorder travsersal of the BST
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->ele);
}
 
// getting data from the user
int read_data()
{
    int ele;
    printf("\nEnter element: ");
    scanf("%d", &ele);
    return ele;
}
