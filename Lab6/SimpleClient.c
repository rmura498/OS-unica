//
// Created by Raffaele Mura on 22/02/22.
//

#include <stdio.h>

#include <stdlib.h>
#include <fcntl.h>

#include <unistd.h>

#define PIPE "/tmp/my_pipe"

int main(void) {
    int fd_pipe;
    char buffer[]="Hello from the client";

    if ((fd_pipe = open(PIPE, O_WRONLY)) == -1) {
        perror("Cannot open the named pipe");
        exit(-1);
    }
    if(write(fd_pipe, buffer, sizeof (buffer))==-1)
    {
        perror("The server is not running");
        exit(-1);
    }

}

