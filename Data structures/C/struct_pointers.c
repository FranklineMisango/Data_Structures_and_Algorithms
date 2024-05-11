#include <stdlib.h>
#include <stdio.h>


struct Rectangle{
    int length;
    int width;
};

int main(){
    
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 10;
    p->width = 5;

    printf("The Length is : %d", p->length);
    printf("The Width is : %d", p->length);

}