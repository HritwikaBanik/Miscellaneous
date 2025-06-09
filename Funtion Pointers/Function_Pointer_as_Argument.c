/*
Used to pass a function to another function.
*/

#include<stdio.h>

void greet(const char* name){
    printf("%s\n", name);
}

void callfunction(void (*func)(const char*), const char* value){
    printf("Hi,");
    func(value);
}

int main(){
    callfunction(greet , "Aunty!");
    return 0;
}

/*
what happens in the compiler?
-----------------------------------------------------
1. Line: callfunction(greet, "Aunty!");
Function Address Resolution:
The compiler replaces the identifier greet with the address of the function greet.
So this becomes essentially:

      callfunction(&greet, "Aunty!");

2.Function Call: callfunction:
You are calling callfunction with two arguments:
      A function pointer to greet
      A string literal "Aunty!" (which decays to a const char*)

3. Inside callfunction
Function Signature:

      void callfunction(void (*func)(const char*), const char* value)

func is a function pointer that takes a const char* and returns void
value is just a pointer to the string "Aunty!"

4.Line: printf("Hi,");
Outputs Hi, to the console
Nothing too special — standard printf execution

5.Line: func(value);
You're calling the function via the function pointer


------------------------------------------------------------------------------
** At runtime:

The function pointer func points to greet
It jumps to the address of greet and passes the "Aunty!" string to it


*** The compiler:

Allocates space for the string "Aunty!" in the read-only data section
Associates greet with its memory address
Replaces function calls with machine code instructions to push arguments and jump to the function's address

**** During Runtime:
Stack frames are created for each function:

main() → callfunction() → greet()

"Aunty!" is passed via register or stack (depending on ABI)
Execution jumps into greet(), which prints "Aunty!"


*/