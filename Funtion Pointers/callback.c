/*
A callback is a use case of a function pointer.
It’s when you pass a function (often using a function pointer) to another function to be called later.
*/

#include <stdio.h>

// A function to be used as a callback
void onEvent(const char* message) {
    printf("Callback triggered: %s\n", message);
}

// A function that takes a callback
void triggerEvent(void (*callback)(const char*), const char* msg) {
    printf("Inside triggerEvent\n");
    callback(msg); // call the callback
}

int main() {
    triggerEvent(onEvent, "Hello from callback!");
    return 0;
}

