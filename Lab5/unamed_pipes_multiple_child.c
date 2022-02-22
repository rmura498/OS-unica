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
#define SIZE 50

typedef struct {
    int pid;
    char text[SIZE];
}message;

int main(int argc, char **argv)
{
    char pmessage[]="Greetings from the parent";
    message m;

    int fd_pipe[4][2]; // one for each communication between parent and that child
    int fd_c2p[2]; // from each child to the parent
    int i;
    int pid;

    char buffer[PIPE_BUF];

    for(i=0;i<4;i++){
        if(pipe(fd_pipe[i])==-1)
        {
            perror("Cannot create the pipe");
            exit(-1);
        }
    }

    if(pipe(fd_c2p)==-1)
    {
        perror("Cannot create the pipe");
        exit(-1);
    }

    for(i=0;i<4;i++){

        if((pid=fork())==-1)
    {
        perror("Cannot create the child process");
        exit(-1);
    }

    switch (pid) {
        case 0:
            close(fd_pipe[i][WRITE]);
            close(fd_c2p[READ]);

            if (read(fd_pipe[i][READ], buffer, PIPE_BUF) == -1) {
                perror("cannot read from the pipe");
                exit(-1);
            }
            printf("Child received from parent: %s\n", buffer);
            m.pid=getpid();
            strcpy(m.text, "Well received");

            if (write(fd_c2p[WRITE], (message *) &m, sizeof (m)) == -1) {
                perror("cannot write to the pipe c2p");
                exit(-1);
            }

            exit(0);
    }
    }
    close(fd_c2p[WRITE]);
    for(i=0;i<4;i++)
    {
        close(fd_pipe[i][READ]);

        if (write(fd_pipe[i][WRITE], (char *) pmessage, strlen(pmessage) + 1) == -1)
        {
            perror("cannot write to the pipe");
            exit(-1);
        }
    }


    while(read(fd_c2p[READ], (message *) &m, sizeof(m))!=0)
    {
        printf("Parent received from child %d: %s\n", m.pid, m.text);
    }


}
