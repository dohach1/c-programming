
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
  node *current=head;
  
  
  while (current ->next !=NULL){
    current=current->next;
    


int main(){
  head=(node*)malloc(sizeof(node));
  
  
