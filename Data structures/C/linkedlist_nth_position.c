#include <stdlib.h>
#include <stdio.h>

// Defining a structure called Node
struct Node {
    int data; // This holds the actual data
    struct Node* Next; // This is a link to the next node
};

void Insert(int data, int n) {
    // This function inserts data at a specified position in the list

    // Creating a new node using malloc
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data; // Setting the data for the new node
    temp1->Next = NULL; // Initially, the new node points to nothing (NULL)

    // Handling the case when the position to insert is at the beginning
    if (n == 1) {
        temp1->Next = head; // Making the new node point to the current head
        head = temp1; // Updating the head to point to the new node
        return; // Exiting the function
    }

    // For other positions, we'll traverse the list
    struct Node* temp2 = head; // Starting from the head
    for (int i = 0; i < n - 2; i++) { // Traverse until the position just before the insertion point
        temp2 = temp2->Next;
    }
    temp1->Next = temp2->Next; // Making the new node point to the node at position 'n'
    temp2->Next = temp1; // Making the node just before 'n' point to the new node
}

void Print() {
    // This function prints all the elements of the linked list

    struct Node* temp = head; // Start from the head of the list
    printf("List is: ");
    while (temp != NULL) { // Traverse until the end of the list
        printf("%d ", temp->data); // Print the data of the current node
        temp = temp->Next; // Move to the next node
    }
    printf("\n"); // Print a new line after printing all elements
}

// Declaring a global variable head which will point to the first node of the list
struct Node* head = NULL;

int main() {
    // Main function where we'll test our linked list operations

    Insert(2, 1); // Inserting 2 at position 1, List: 2
    Insert(3, 2); // Inserting 3 at position 2, List: 2,3
    Insert(4, 1); // Inserting 4 at position 1, List: 4,2,3
    Insert(5, 2); // Inserting 5 at position 2, List: 4,5,2,3
    Print(); // Printing the final list
    return 0;
}
