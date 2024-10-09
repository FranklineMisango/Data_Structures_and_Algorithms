#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main () {

    int n;
    int i;
    int j;
    int square = 0;
    
    printf("Plug in the values : ");
    scanf("%d", &n);

    //Testing with size n
    for (i = 0 ; i < n ; i++) {
        for (j = 0; j < n; j++) {
            square++;

        }
    }
    printf("The answer is : %d", square);

    return 0;
}