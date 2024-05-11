//This program is to insert at the beginning only 
//The two libraries allows us to use malloc and define structures
#include <stdlib.h>
#include <stdio.h>

//Inserting a node at beginning
struct Node {
    int data; // can define for int or other type
    struct Node* Next; //The Next below is the link 
};

//Here, I declare the initial pointer, Not A NODE
struct Node* head;
//Inserting at the beginning of the positions
void Insert(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); //Storing the address of the new node 
    temp->data = x;
    temp->Next = head; // To what the previous node's Next was; otherwise it should be NULL
    /**
     * You can think of it as : 
     * if (head!=NULL) temp -> next =  head
    */
    head = temp; //The head pointer variable now points to the new node we want to initialize
}
void Print() {
    //If the address is not NULL/empty, then print the value of the data
    struct Node* temp = head;
    printf("List is : ");
    while (temp != NULL) {
        printf("%d ", temp->data); // Added a space for readability
        temp = temp->Next;
    }
    printf("\n"); 
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
