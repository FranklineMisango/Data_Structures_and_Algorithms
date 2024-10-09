// Computation for speed of the second week algorithms

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main () {

    int n;
    int square;
    
    printf("Plug in the values : ");
    scanf("%d", &n);

    //Test 1 with size n
    square = (n * n);

    printf("The answer is : %d", square);

    return 0;
}