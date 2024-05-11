//Basic practice of Arrays
#include <stdio.h>
#include <stdlib.h>

int main(){
    int A[4];
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 4;
    A[4] = 5;

    for(int i = 0; i < 5; i++){
        printf("%d", A[i]);
    }

    printf("%d", sizeof(A)); //prints the space of array occupation in the memory
}