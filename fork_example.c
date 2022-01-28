//
// Created by Raffaele Mura on 28/01/22.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    printf("The parent PID is: %d\n", getpid());
    int pid;
    int a,b,c;
    a=3;
    b=-2;
    c=5;

    if( (pid= fork()) == -1)
    {
        perror("Error in the fork() call");
        exit(-1);
    }

    switch (pid) {
        case 0:
            printf("The child PID is: %d\n", getpid());
            printf("CHILD: a = %d\n b = %d\n c = %d\n", a-2, b+1, c-7);
            break;

        default:
            printf("PARENT: a = %d\n b = %d\n c = %d\n", a, b, c);
            break;


    }


}