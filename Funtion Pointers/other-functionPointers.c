/*
1.Callout func : often implemented using function pointers, especially in RTOS or kernel code.
2.Notifications : Not necessarily a function pointer.
*/
-------------------------------------------
/*A callout is typically used in low-level systems (e.g., OS kernels or embedded software) 
to describe a delayed or scheduled function execution.
It’s not standard C terminology, but appears in RTOS kernels or drivers.

Use Case:

Schedule an action after a time delay
Timer interrupt routines
Deferred execution of tasks

Example (conceptual):

*/ //Pseudo-code (RTOS-style)
schedule_callout(myFunc, delay_ms);
//Think of callouts as timed callbacks or deferred function executions.


-------------------------------------------
/*A notification is a message or signal sent from one component to another to indicate that an event has occurred. 
It does not carry out logic, but alerts another part of the system to respond.

Use Case:

Inter-process communication
OS signals
Event handling in drivers (e.g., device finished initialization).
*/
#include <stdio.h>

void notify(const char* message) {
    printf("🔔 Notification: %s\n", message);
}

int main() {
    notify("File download complete!");
    return 0;
}
