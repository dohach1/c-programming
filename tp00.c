
                                                          //dynamic_array//
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


                                                            //queue//
//with int//

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE]; 
int front = 0, rear = -1; // empty queue

void push(int value) { 
    if (rear >= MAX_QUEUE_SIZE - 1) { // Check if the queue is already full
        printf("Error: queue overflow\n"); 
        return; 
    }
    rear++; // Increment the rear index
    queue[rear] = value; // Add the value to the rear of the queue
}

int pop() { // Function for removing and returning the value at the front of the queue
    if (front > rear) { //empty
        printf("Error: queue underflow\n"); 
        return -1; //error code
    }
    int value = queue[front]; 
    front++; 
    return value; 
}

int peek() { // Function for getting the value at the front of the queue without removing it
    if (front > rear) { 
        printf("Error: queue empty\n"); 
        return -1; 
    }
    return queue[front]; // Return the value at the front of the queue
}

int main() { // Main function for testing the queue implementation
    push(10); // Push the value 10 onto the queue
    printf("Front element: %d\n", peek());       // Print the value at the front of the queue without removing it
    printf("Pop: %d\n", pop());      // Pop the value at the front of the queue and print it
    printf("Pop: %d\n", pop());      // Attempt to pop a value from an empty queue, resulting in an error message
    return 0;
}


//with char//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

char queue[MAX_QUEUE_SIZE];
int front = 0, rear = -1; // empty queue

void push(char value) {
    if (rear >= MAX_QUEUE_SIZE - 1) { // Check if the queue is already full
        printf("Error: queue overflow\n"); 
        return; 
    }
    rear++; // Increment the rear index
    queue[rear] = value; // Add the value to the rear of the queue
}

char pop() { // Function for removing and returning the value at the front of the queue
    if (front > rear) { //empty
        printf("Error: queue underflow\n"); 
        return '\0'; //error code
    }
    char value = queue[front]; 
    front++; 
    return value; 
}

char peek() { // Function for getting the value at the front of the queue without removing it
    if (front > rear) { 
        printf("Error: queue empty\n"); 
        return '\0'; 
    }
    return queue[front]; // Return the value at the front of the queue
}
int main() { // Main function for testing the queue implementation
    push('a'); // Push the value 'a' onto the queue
    printf("Front element: %c\n", peek());       // Print the value at the front of the queue without removing it
    printf("Pop: %c\n", pop());      // Pop the value at the front of the queue and print it
    printf("Pop: %c\n", pop());      // Attempt to pop a value from an empty queue, resulting in an error message
    return 0;
}





                                              //stack//
//with int //

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1; // initialize stack as empty (-1)

void push(int value) {
    if (top >= MAX_STACK_SIZE - 1) {    // Check if the stack is already full
        printf("Error: stack overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top < 0) {  // Check if the stack is already empty
        printf("Error: stack underflow\n"); 
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}

int peek() {
    if (top < 0) {
        printf("Error: stack empty\n");
        return -1;
    }
    return stack[top];  // Return the value at the top of the stack
}

int main() {
    push(100);
    printf("Top element: %d\n", peek());  // Print the value at the top of the stack without removing it
    printf("Pop: %d\n", pop());  // Pop the value at the top of the stack and print it
    
    printf("Pop: %d\n", pop()); // should result in underflow error
    return 0;
}

//with char//


#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE];
int top = -1; // initialize stack as empty (-1)

void push(char value) {
    if (top >= MAX_STACK_SIZE - 1) {    // Check if the stack is already full
        printf("Error: stack overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

char pop() {
    if (top < 0) {  // Check if the stack is already empty
        printf("Error: stack underflow\n"); 
        return '\0';
    }
    char value = stack[top];
    top--;
    return value;
}

char peek() {
    if (top < 0) {  
        printf("Error: stack empty\n");
        return '\0';
    }
    return stack[top];  // Return the value at the top of the stack
}

int main() {
    push('a');
    printf("Top element: %c\n", peek());  // Print the value at the top of the stack without removing it
    printf("Pop: %c\n", pop());  // Pop the value at the top of the stack and print it
    
    printf("Pop: %c\n", pop()); // should result in underflow error
    return 0;
}


                                                           //list//


#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 

int list[MAX_LIST_SIZE]; 
int length = 0;
void append(int value) { // appending a value to the end of the liste
    if (length >= MAX_LIST_SIZE) {  // Check full
        printf("Error: list overflow\n"); 
        return;
    }
    list[length] = value; // Add the value to the end of the list
    length++;
}

int main() { 
    append(100); // Append the value 100 to the list
    for (int i = 0; i < length; i++) {     //print each value
        printf("%d ", list[i]);
    }
    return 0; 
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 

char list[MAX_LIST_SIZE]; 
int length = 0;

void append(char value) { // appending a value to the end of the list
    if (length >= MAX_LIST_SIZE) {  // Check full
        printf("Error: list overflow\n"); 
        return;
    }
    list[length] = value; // Add the value to the end of the list
    length++;
}

int main() { 
    append('d'); // Append the character 'H' to the list
    append('r'); // Append the character 'o' to the list
    
    for (int i = 0; i < length; i++) {     //print each character(value)
        printf("%c", list[i]);
    }
    return 0; 
}

