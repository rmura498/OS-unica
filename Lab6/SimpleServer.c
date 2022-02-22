//
// Created by Raffaele Mura on 22/02/22.
//

#include <stdio.h>

#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

#define PIPE "/tmp/my_pipe"

int main(void) {
    int fd_pipe;
    char buffer[PIPE_BUF];
    int bytes_read;

    if (mkfifo(PIPE, 0666) == -1) {
        perror("Cannot create the named pipe");
        exit(-1);
    }
    if ((fd_pipe = open(PIPE, O_RDWR)) == -1) {
        perror("Cannot open the named pipe");
        exit(-1);
    }
    while((bytes_read=read(fd_pipe, buffer, sizeof(buffer)))!=0)
        write(1, buffer, bytes_read);

}