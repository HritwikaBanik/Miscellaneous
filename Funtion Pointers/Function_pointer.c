/*
Definition :
1 .A function pointer is just a variable 
2 .that stores the address of a function.
3 .You can then use that pointer to call the function.
*/

#include<stdio.h>

void game(){
    printf{"Hi ! Welcome to the Function pointer Game world!"};
}
int main(){

    void (void (*play),()) = game;
    return 0;
}