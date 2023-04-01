
        //linkedlist //graphs
  
    //last version of code 
    //1.add last node
    
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
  
    
                                               //delete last node 
    
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

void deleteLastNode(struct node **head)
{
    if (*head == NULL) {
        return;  // empty list
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;  // single node list
    }
    struct node *prev = NULL;
    struct node *current = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    free(current);
    prev->next = NULL;
}


int main()
{
     struct node *head = NULL;

     addLast(&head,10);
     addLast(&head,20);
     addLast(&head,30);

     printList(head);
     deleteLastNode(&head);

printf("The New Linked List:\n");
printList(head);

     return 0;
}
  
