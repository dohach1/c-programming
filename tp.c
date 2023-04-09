
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
  


         //graphs 



#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_vertices;
    int** adj_matrix;
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->adj_matrix = (int**) malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = (int*) calloc(num_vertices, sizeof(int));
    }
    return graph;
}

void add_edge(Graph* graph, int src, int dest) {
    // add edge from src to dest
    graph->adj_matrix[src][dest] = 1;
    // add edge from dest to src (undirected graph)
    graph->adj_matrix[dest][src] = 1;
}

void print_graph(Graph* graph) {
    printf("Adjacency matrix:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    int num_vertices = atoi(argv[1]);
    int num_edges = atoi(argv[2]);
    Graph* graph = create_graph(num_vertices);
    printf("Enter edges (src dest):\n");
    int src, dest;
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &src, &dest);
        add_edge(graph, src-1, dest-1); // adjust indices to start from 0
    }
    print_graph(graph);
    return 0;
}


//binary search tree



 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int height;
    int value;
}Nd;

int max(int a, int b)
{
    return a > b ? a : b;
}

Nd* newNode(int value)
{
    Nd* node = (Nd*)malloc(sizeof(Nd));
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->value = value;
}

int height(Nd* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

void rightRotation(Nd** root_adr)
{
    Nd* root = *root_adr;
    Nd* leftChild = root->left;
    Nd* leftChildRightChild = leftChild->right;
    leftChild->right = root;
    root->left = leftChildRightChild;
    root->height = max(height(root->left), height(root->right)) + 1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;
    *root_adr = leftChild;
}

void leftRotation(Nd** root_adr)
{
    Nd* root = *root_adr;
    Nd* rightChild = root->right;
    Nd* rightChildLeftChild = rightChild->left;
    rightChild->left = root;
    root->right = rightChildLeftChild;
    root->height = max(height(root->left), height(root->right)) + 1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;
    *root_adr = rightChild;
}

void insert(Nd** root_adr, int value)
{
    Nd *root = *root_adr;
    if (root == NULL)
    {
        root = newNode(value);
        *root_adr = root;
        return;
    }
    if (root->value > value)
        insert(&(root->left), value);
    else if (root->value < value)
        insert(&(root->right), value);
    else
        return;
    root->height = max(height(root->left), 
                       height(root->right)) +1;
    int balance = height(root->left) - height(root->right);
    if (balance > 1)
    {
        if (value > root->left->value)
        {
            leftRotation(&(root->left));
            rightRotation(&root);
        }
        else
            rightRotation(&root);
    }
    if (balance < -1)
    {
        if (value < root->right->value)
        {
            rightRotation(&(root->left));
            leftRotation(&root);
        }
        else
            leftRotation(&root);
    }
    *root_adr = root;
}

bool find(Nd* root, int value)
{
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    else if (root->value > value)
        return find(root->left, value);
    else
        return find(root->right, value);
}

             //free tree

void free_tree(Nd* root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
