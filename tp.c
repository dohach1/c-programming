
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
      lastn->=element;
    


int main(){
  head=(node*)malloc(sizeof(node));
  struct node *head=NULL;
  append(&head,10);
  
  
  
