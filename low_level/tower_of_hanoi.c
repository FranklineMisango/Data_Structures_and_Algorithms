#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**Implementing the tower of hanoi */
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) 
    
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {

    clock_t start, end;
    
    int n = 5; // Number of disks

    tower_of_hanoi(n, 'A', 'C', 'B'); // A, B and C are the rod names
    
    return 0;
}