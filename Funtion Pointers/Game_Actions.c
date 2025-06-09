/*
You’re making a game. The player can choose different actions: Jump, Shoot, or Run.
Instead of writing a long if-else, you can use function pointers.
*/

#include<stdio.h>

void jump(){printf("Jump!\n");};
void run(){printf("Run!\n");};
void walk(){printf("walk!\n");};


int main(){
    
    int choice ;
    //Created an array of 3 function pointers 
    void (*actions[3])()={jump ,run , walk};  

    printf("Enter your choice : 0=jump 1=run 2=walk");
    scanf("%d",&choice);

    if(choice >=0 && choice < 3){
        action[choice]();
    }
    else printf("Invalid choice!\n");

    return 0 ;
}
