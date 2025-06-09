/*
Definition :
1 .A function pointer is just a variable 
2 .that stores the address of a function.
3 .You can then use that pointer to call the function.
*/
--------------------------------------------------------------------------------------------------
#include<stdio.h>

void game(){
    printf("Hi ! Welcome to the Function pointer Game world!");
}
int main(){

    void (*play)() = game;   //syntax :   return_typeof_earlierFunc (*funcName)(parameter) | function pointer declaration
    play();  //calling to the function using pointer play

    return 0;
}


/*
output:
"Hi ! Welcome to the Function pointer Game world!"
*/

--------------------------------------------------------
/*use case :
A function pointer lets us:

1.Store a function in a variable

2.Pass a function as an argument

3.Choose which function to run at runtime

4.Switch behavior dynamically

5.You’re making a game. The player can choose different actions: Jump, Shoot, or Run.
Instead of writing a long if-else, you can use function pointers.
*/
----------------------------------------------------------

