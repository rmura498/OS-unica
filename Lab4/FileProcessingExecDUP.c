//
// Created by Raffaele Mura on 21/02/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {

    int k;
    int pid;
    int fd;

    if((fd=open("./MarkSummary.txt",O_CREAT|O_WRONLY))==-1){
        perror("Unable to open the output file");
        exit(-1);
    }

    printf("fd: %d\n\n", fd); // it will be 3

    for(k=1; k<argc; k++){

        if((pid=fork())==-1){
            perror("Unable to create a new process");
            exit(-1);
        }

        if(pid==0) {
            if(dup2(fd, 1)==-1){
                perror("Unable to open the output file");
                exit(-1);
            }

            if(execl("./SingleFileProcessing","FileProcessing",argv[k], (char *)0)==-1){
                perror("Unable to create a new process");
                exit(-1);
            }

            }
        }
        }

