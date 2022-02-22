//
// Created by Raffaele Mura on 21/02/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>


typedef struct {
    char subject[30];
    int mark;
    int credits;
} transcript;


int main(int argc, char **argv) {

    FILE *fp;
    int N;
    int i;
    transcript t[50];
    int SumWeightedMarks, SumCredits, MaxMark;
    float avg;

    int fd_pipe;
    int client_pipe;
    message m;
    int bytes_read;

    char output[PIPE_BUF];

    if (mkfifo(PIPE, 0666) == -1) {
        perror("Cannot create the named pipe");
        exit(-1);
    }
    if ((fd_pipe = open(PIPE, O_RDWR)) == -1) {
        perror("Cannot open the named pipe");
        exit(-1);
    }

    while((bytes_read=read(fd_pipe, &m, sizeof(message)))!=0)
    {
        if ((fp = fopen(m.filename, "r")) == NULL) {
            perror("Unable to open the file");
            exit(-1);
        }

        fscanf(fp, "%d", &N);

        for (i = 0; i < N; i++)
            fscanf(fp, "%s %d %d", t[i].subject, &t[i].mark, &t[i].credits);

        SumWeightedMarks = 0;
        SumCredits = 0;
        MaxMark = 0;


        for (i = 0; i < N; i++) {
            SumWeightedMarks += t[i].mark * t[i].credits;
            SumCredits += t[i].credits;
            if (MaxMark < t[i].mark)
                MaxMark = t[i].mark;

        }

        avg = (float) SumWeightedMarks / SumCredits;

        if((client_pipe=open(m.private_pipe,O_WRONLY))==-1)
        {
            perror("Unable to open the private pipe");
            exit(-1);
        }

        sprintf(output, "Student %s: Average: %f and Maximum Mark: %d", m.filename, avg, MaxMark);
        write(client_pipe, output, strlen(output));
        close(client_pipe);
    }

}




