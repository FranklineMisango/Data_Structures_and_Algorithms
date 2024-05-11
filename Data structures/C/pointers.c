#include <stdlib.h>
#include <stdio.h>


int main(){

    int a = 10;
    printf("%d", a);
    int *pointer;
    pointer = &a;
    printf("%d", *pointer); //If you leave the * out, we will get the address of the pointer


    //Pointer to an array
    int A[5] = {1,2,3,4,5};
    int *p; // We can allocate p for each value in A if we want by : p=A[0] etc
    p=A;

    for(int i=0; i<5; i++){
        printf("The values are : %d", p[i]); //or A[i]
    };

    //creating the array on a heap

    int* pointer_heap = (int *)malloc(5 * sizeof(int));
    pointer_heap[0]=1;
    pointer_heap[1]=2;
    pointer_heap[2]=3;
    pointer_heap[3]=4;
    pointer_heap[4]=5;

     for(int i=0; i<5; i++){
        printf("The values in the heap are : %d", pointer_heap[i]); //or A[i]
    };


}