// In this code I Want to explore the concept of dynamic memory allocation
// Malloc allocates space for the array
//Calloc has a different structure 
// Realloc changes the size of the initial memory size in the heap
#include <stdio.h>
#include <stdlib.h>

//We cannnot dynamically alocate the size of array (n) during runtime hence we need to assign the memory randomly
int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    //uncomment to test either feautures
    //int *A = (int *)malloc(n * sizeof(int));  //dynamically allocated for the array
    int *A  =(int *)calloc(n, sizeof(int)); // Calloc function use

    //Filling the array randomly

    for(int i = 0; i<n; i++){
        A[i] = i + 1;
    };
    
    //free (A); //The data from that memory is erased and you should expect garbage values as the next output instead of 0 - 9 with n = 10

    for(int i = 0 ; i < n ; i++){
        printf("%d ", A[i]);
    }


    //Testing the realloc function 
    int *B = (int*)realloc(A, 2*n*sizeof(int)); //The n changes to the size of 2n values which is 20
    printf("Previous block address is %d and the new address after realloc B is %d", A, B);
    for(int i = 0 ; i < 2 * n ; i++){
        printf("%d ", B[i]);
    }

}