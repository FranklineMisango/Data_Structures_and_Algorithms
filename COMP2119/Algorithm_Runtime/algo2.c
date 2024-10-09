// Computation for speed of the second week algorithms

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main () {

    int n;
    int i;
    int square = 0;
    
    printf("Plug in the values : ");
    scanf("%d", &n);

    //Test 1 with size n
    for (i = 0 ; i < n ; i++) {
        square = square + n;
    }
    printf("The answer is : %d", square);

    return 0;
}