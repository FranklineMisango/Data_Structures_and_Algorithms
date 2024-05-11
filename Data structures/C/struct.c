//Basic practice of structures
#include <stdio.h>
#include <stdlib.h>


struct rectangle{
    int length;
    int breadth;
};
int main(){
    struct rectangle R;
    R.length = 10;
    R.breadth = 10;

    // Other population method would be Struct Rectangle R = {10, 10}

    printf("The size of the structure is  : %d", sizeof(R));

}