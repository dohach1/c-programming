#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a dynamic array
struct dynamic_array {
    int *arr;    // Pointer to an integer array
    int len;     // Length of the array
    int allocated;     // Allocated size of the array
};

// Function to append an element to a dynamic array
void append(struct dynamic_array *A, int element) {
    // Check if the length of the array is equal to the allocated size
    if (A->len == A->allocated) {
        // If so, double the allocated size
        A->allocated *= 2;
        // Create a new array with the new allocated size
        int *new_arr = (int *) malloc(sizeof(int) * (A->allocated));
        // Copy the elements from the old array to the new array
        for (int i = 0; i < A->len; i++) {
            new_arr[i] = A->arr[i];
        }
        // Free the old array
        free(A->arr);
        // Assign the new array to the arr member variable of the dynamic array
        A->arr = new_arr;
    }
    // Add the new element to the end of the array
    A->arr[A->len] = element;
    // Increment the length of the array
    A->len += 1;
}

int main() {
    // Initialize a dynamic array
    struct dynamic_array A;
    A.len = 0;
    A.allocated = 1;
    A.arr = (int *) malloc(sizeof(int) * A.allocated);
    // Free the allocated memory
    free(A.arr);
    return 0;
}



//the queue//

#include <stdio.h>
#include <stdlib.h>
struct queue{
    int n;
    int front;
    int rear;
    int *arr;
};
void enqueue(struct queue *B,int s){
    if(B->arr==NULL){
        B->front=-1;
        B->rear=-1;
    }
    B->n++;
    B->arr=realloc(B->arr,B->n*sizeof(int));
    if (B->arr == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    };
    B->arr[B->n-1]=s;
    B->rear++;
    if (B->front == -1) {
        B->front = 0;
    };

}
void dequeue(struct queue *B){
    if(B->arr!=NULL){
        for(int i=0;i<B->n-1;i++){
            B->arr[i]=B->arr[i+1];
        }
        B->front++;
        B->n--;
        B->arr=realloc(B->arr,B->n*sizeof(int));
        if(B->front==B->rear){
            B->front=-1;
            B->rear=-1;
        }
    }
}
int main() {
    struct queue B;
    int n;
    B.arr=NULL;
    B.n=0;
    enqueue(&B,1);
    enqueue(&B,6);
    enqueue(&B,3);
    enqueue(&B,9);
    enqueue(&B,5);
    dequeue(&B);
    for(int i=0;i<B.n;i++){
        printf("%d\n",B.arr[i]);
    }
    free(B.arr);
    return 0;
}



// the stack //

#include <stdio.h>
#include <stdlib.h>
struct stack{
    int *arr;
    int n;
};
void push(struct stack *A,int data){
    A->n++;
    A->arr=realloc(A->arr,A->n*sizeof(int));
    A->arr[A->n-1]=data;
    count++;
    if(data > A->n){
        A->arr=realloc(A->arr, 2*A->n*sizeof(int));
        A->arr[A->n]=data;
    int i, j;
    for (i = 0, j = 0; j < A->n; j++) {
        if (A->arr[j] != 0) {
            A->arr[i++] = A->arr[j];
        };
    };
    A->n = i;
    A->arr = realloc(A->arr, A->n * sizeof(int));
};

    }
void pop(struct stack *A){
    if(A->arr==NULL){
        return;
    }else{
        if (A->n <= 0) {
            A->n = 0;
            A->arr = NULL;
        }else{
            A->n--;
            A->arr=(int*)realloc(A->arr,A->n * sizeof(int));
        }
    }
}

int main() {
    struct stack A;
    int n;
    A.arr=NULL;
    A.n=0;
    push(&A,1);
    push(&A,2);
    push(&A,3);
    push(&A,4);
    push(&A,5);
    push(&A,6);
    push(&A,7);
    push(&A,8);
    pop(&A);
    for(int i=0;i<A.n;i++){
        printf("%d",A.arr[i]);
    }
    free(A.arr);
 
    return 0;
}

