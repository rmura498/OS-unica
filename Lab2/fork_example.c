//
// Created by Raffaele Mura on 18/02/22.
//

#include <stdio.h>
#include <unistd.h> // to use fork
#include <stdlib.h> //to use exit

int main(int arg, char **argv){

    int a,b,c;
    int pid;

    printf("The PARENT PID is:%d\n", getpid());

    a = 3;
    b = -2;
    c = 5;

    if((pid = fork()) == -1)
    {
        perror("Error in the fork call");
        exit(-1);
    }

    switch(pid){
        case 0:
            printf("The CHILD PID is:%d\n", getpid());
            printf("CHILD\n: a = %d\n b = %d\n c = %d\n", a-2, b+1, c-7);
            break;
        default:
            printf("The PARENT PID is:%d\n", getpid());
            printf("Parent\n: a = %d\n b = %d\n c = %d\n", a, b, c);
            break;
    }
    printf("bye\n\n");
}