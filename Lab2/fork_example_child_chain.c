//
// Created by Raffaele Mura on 21/02/22.
//

#include <stdio.h>
#include <unistd.h> // to use fork
#include <stdlib.h> //to use exit
#include <sys/types.h> // to use wait


int main(int arg, char **argv){

    int i;
    int pid;
    int status;

    printf("The PARENT PID is:%d\n", getpid());

    for(i=0; i<4;i++) {
        if ((pid = fork()) == -1) {
            perror("Error in the fork call");
            exit(-1);
        }
        switch (pid) {
            case 0:
                printf("Pid:[%d] PPid[%d]\n", getpid(), getppid());
                exit(1);

            default:
                printf("Pid:[%d] PPid[%d]\n", getpid(), getppid());

        }
    }
}