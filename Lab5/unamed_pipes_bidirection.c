//
// Created by Raffaele Mura on 22/02/22.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define READ 0
#define WRITE 1

int main(int argc, char **argv)
{
    char message[]="Greetings from the parent";
    char message_c2p[]="Well received";

    int fd_pipe[2];
    int fd_c2p[2];
    int pid;

    char buffer[PIPE_BUF];

    if(pipe(fd_pipe)==-1)
    {
        perror("Cannot create the pipe");
        exit(-1);
    }
    if(pipe(fd_c2p)==-1)
    {
        perror("Cannot create the pipe");
        exit(-1);
    }

    if((pid=fork())==-1)
    {
        perror("Cannot create the child process");
        exit(-1);
    }

    switch (pid) {
        case 0:
            close(fd_pipe[WRITE]);
            close(fd_c2p[READ]);
            if(read(fd_pipe[READ], buffer, PIPE_BUF)==-1)
            {
                perror("cannot read from the pipe");
                exit(-1);
            }
            printf("Child received from parent: %s\n", buffer);
            if(write(fd_c2p[WRITE], message_c2p, strlen(message_c2p)+1)==-1)
            {
                perror("cannot write to the pipe c2p");
                exit(-1);
            }

            exit(0);


        default:
            close(fd_pipe[READ]);
            close(fd_c2p[WRITE]);
            if(write(fd_pipe[WRITE], message, strlen(message)+1)==-1)
            {
                perror("cannot write to the pipe");
                exit(-1);
            }
            if(read(fd_c2p[READ], buffer, PIPE_BUF)==-1)
            {
                perror("cannot read from the pipe c2p");
                exit(-1);
            }
            printf("Parent received from child: %s\n", buffer);

    }




}
