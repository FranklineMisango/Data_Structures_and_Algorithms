#include <stdlib.h>
#include <stdio.h>

//Inserting a node at beginning
struct Node {
    int data; // can define for int or other type
    struct Node* Next; //The Next below is the link 
};
struct Node* head; // The head variable

void Reverse(){
    struct Node* current, *previous, *Next;
    current = head;
    previous = NULL;

    while(current=!NULL){
        Next = current -> Next;
        current->Next = previous;
        previous = current;
        current = Next;
    }

}



void Insert(int x) {
    // This function inserts a new node with data 'x' at the beginning of the list

    // Creating a new node using malloc
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x; // Setting the data for the new node
    temp->Next = head; // Making the new node point to the current head

    head = temp; // Updating the head to point to the new node
}

int main() {
    head = NULL; //Empty list and doesn't point anywhere
    //Define the operation you want implementation 
    printf("How many numbers into the list?: ");
    int n, i, x;
    scanf("%d", &n); // Fixed: properly initialize n by reading its value
    for (i = 0; i < n; i++) {
        printf("Enter number: "); // Optional: prompt for each number
        scanf("%d", &x);
        Insert(x);
        Print();
    }
    return 0;
}
