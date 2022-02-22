//
// Created by Raffaele Mura on 22/02/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>



int main(int argc, char **argv) {
    int public_pipe;
    int private_pipe;

    char buffer[PIPE_BUF];
    int bytes_read;
    message m;

    sprintf(m.private_pipe, "/tmp/client%d",getpid());

    if (mkfifo(m.private_pipe, 0666) == -1) {
        perror("Cannot create the private pipe");
        exit(-1);
    }
    if ((private_pipe = open(m.private_pipe, O_RDWR)) == -1) {
        perror("Cannot open the named pipe");
        exit(-1);
    }

    if ((public_pipe = open(PIPE, O_WRONLY)) == -1) {
        perror("Cannot open the public pipe");
        exit(-1);
    }

    strcpy(m.filename, argv[1]);
    if(write(public_pipe, &m, sizeof(message))==-1)
    {
        perror("The server is not running");
        exit(-1);
    }
    if((bytes_read=read(private_pipe,buffer, PIPE_BUF))==-1)
    {
        perror("Error reading from the private pipe");
        exit(-1);
    }
    write(1, buffer, bytes_read);
    close(private_pipe);
    if(unlink(m.private_pipe)==-1)
    {
        perror("error removing the private pipe");
        exit(-1);
    }

}


