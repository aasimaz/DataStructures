#include<stdio.h>
#include<malloc.h>

struct node *createCircularLinkedList(int);
void displayCircularLinkedList(struct node *);

//Declaring node
struct node{
    int data;
    struct node *next;
};

int main(){
    int n;
    struct node *head;

    printf("Enter the size of linked list : ");
    scanf("%d",&n);

    //Calling function to create node
    head=createCircularLinkedList(n);

    //Calling function to display list
    displayCircularLinkedList(head);

    return 0;
}

struct node *createCircularLinkedList(int n){
    int i;
    struct node *head=NULL;
    struct node *newNode, *ptr;

    for(i=0;i<n;i++){
        //Creating a node
        newNode=(struct node *)malloc(sizeof(struct node));

        //Assigning data to newly created node
        printf("Enter %d node data : ",(i+1));
        scanf("%d",&newNode->data);

        /*If list is empty assign the address of newly created node
		to head*/
        if(head==NULL){
            newNode->next=newNode;
            head=newNode;
        }else{
            /* If list already have few elements then loop through
			list and add newly created node at the end of list*/
            ptr=head;
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=newNode;
            newNode->next=head;
        }
    }
    return head;
}

void displayCircularLinkedList(struct node *head){
    struct node *ptr;

    //If list is empty
    if(head==NULL){
        printf("The Linked List is Empty");
    }else{
        /*If list has elements then loop through the loop and
		print elements one by one in sequential manner*/
        ptr=head;
        while(ptr->next!=head){
            printf("The value of node is %d and their address is %u\n",ptr->data,ptr);
            ptr=ptr->next;
        }
        printf("The value of node is %d and their address is %u\n",ptr->data,ptr);
    }
}