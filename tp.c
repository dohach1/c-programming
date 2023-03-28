#include<stdio.h>
#include<stdlib.h>

typedef struct s_node{
  int data;
  struct s_node* next;
}node;
node *head;
node*last;
void append (int x){
  node* element = (node*)malloc(sizeof(node));
  element->data=x;
  element->next=NULL;
  if(*head==NULL){
    *head=element;
  else{
    struct s_node *lastn=*head
    while (lastn ->next !=NULL){
      lastn=lastn->next;
    }
      lastn->next=element;
    
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}


int main(){
  head=(node*)malloc(sizeof(node));
  struct node *head=NULL;
  append(&head,10);
  append(&head,100);
  append(&head,1000);
  printList(head);
  return 0;
}
  
    //last version 
    
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};


void addLast(struct node **head, int x)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data =x;
    newNode->next= NULL;
    if(*head == NULL)       //if head is NULL, it is an empty list
         *head = newNode;
    else                  //find the last node and add the newNode
    {
        struct node *lastNode = *head;
        while(lastNode->next != NULL) 
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;    //add the newNode at the ende
    }

}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL) //print data
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
     struct node *head = NULL;

     addLast(&head,10);
     addLast(&head,100);
     addLast(&head,1020);

     printList(head);

     return 0;
}
  
  
