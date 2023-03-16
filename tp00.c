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
