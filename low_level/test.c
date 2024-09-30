#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main() {

    clock_t start, end;

    int number;

    printf("Enter a number: ");
    if (scanf("%d", &number) != 1) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // implement factorial of 1910 * n! + 316 * number ^ number 
    result = pow(pi, number)
    printf("Pi to the power of %d is: %f\n", number, result);
    return 0;

}
