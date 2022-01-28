//
// Created by Raffaele Mura on 28/01/22.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    printf("The parent PID is: %d\n", getpid());
    int a,b,c;
    a=3;
    b=-2;
    c=5;

    if(fork()==0)
    {
        printf("The child PID is: %d\n", getpid());
        printf("CHILD: a = %d\n b = %d\n c = %d\n", a-2, b+1, c-7);
    }
    else
    {

        printf("PARENT: a = %d\n b = %d\n c = %d\n", a, b, c);
    }
    printf("[%d] Bye\n\n", getpid());
}