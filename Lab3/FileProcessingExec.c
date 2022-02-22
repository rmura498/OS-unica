//
// Created by Raffaele Mura on 21/02/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {

    int k;
    int pid;

    for(k=1; k<argc; k++){

        if((pid=fork())==-1){
            perror("Unable to create a new process");
            exit(-1);
        }

        if(pid==0) {
            if(execl("./SingleFileProcessing","FileProcessing",argv[k], (char *)0)==-1){
                perror("Unable to create a new process");
                exit(-1);
            }

            }
        }
        }

