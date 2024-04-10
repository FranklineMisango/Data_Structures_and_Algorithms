#include <stdlib.h>
#include <stdio.h>

// Defining a structure called Node
struct Node {
    int data; // This holds the actual data
    struct Node* Next; // This is a link to the next node
};

void Insert(int x) {
    // This function inserts a new node with data 'x' at the beginning of the list

    // Creating a new node using malloc
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x; // Setting the data for the new node
    temp->Next = head; // Making the new node point to the current head

    head = temp; // Updating the head to point to the new node
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

void delete(int n) {
    // This function deletes the node at position 'n' from the list

    struct Node* temp1 = head;

    // Handling the case when the node to delete is the first node
    if (n == 1) {
        head = temp1->Next; // Update head to point to the next node
        free(temp1); // Free the memory occupied by the deleted node
        return; // Exit the function
    }

    // For other positions, we'll traverse the list
    int i;
    for (i = 0; i < n - 2; i++) {
        temp1 = temp1->Next; // Traverse until the node just before the one to be deleted
    }

    struct Node* temp2 = temp1->Next; // Temp2 points to the node to be deleted
    temp1->Next = temp2->Next; // Adjusting the links to bypass the node to be deleted
    free(temp2); // Free the memory occupied by the deleted node
}

// Declaring a global variable head which will point to the first node of the list
struct Node* head = NULL;

int main() {
    // Main function where we'll test our linked list operations

    Insert(2); // Inserting 2 at the beginning of the list
    Insert(3); // Inserting 3 at the beginning of the list
    Insert(4); // Inserting 4 at the beginning of the list
    Insert(5); // Inserting 5 at the beginning of the list

    int n;
    printf("Enter the position of the data for deletion: ");
    scanf("%d", &n); // Getting the position from the user

    delete(n); // Deleting the node at the specified position
    Print(); // Printing the final list after deletion

    return 0;
}
