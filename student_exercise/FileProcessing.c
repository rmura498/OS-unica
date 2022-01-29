//
// Created by Raffaele Mura on 29/01/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    char subject[30];
    int mark;
    int credits;

} transcript;

int main(int argc, char **argv) {
    /* we have to:
     * get the name of the file
     * open the file
     * read the file
     * compute the values
     * print on the screen
     * */

    char filename[50];
    FILE *fp;
    int N;
    int i, k;
    int pid;
    transcript t[50];
    int SumWeightedMarks, SumCredits, MaxMark;
    float avg;

    /*printf("Please provide the filename");
    scanf("%s", filename);*/

    for (k = 1; k < argc; k++) {

        if ((pid = fork()) == -1) {
            perror("Unable to create new process");
            exit(-1);
        }
        if (pid == 0) {

            if ((fp = fopen(argv[k], "r")) == NULL) {
                perror("Unable to open the file");
                exit(-1);
            }

            fscanf(fp, "%d", &N);

            for (i = 0; i < N; i++) {
                fscanf(fp, "%s %d %d", t[i].subject, &t[i].mark, &t[i].credits);
            }
            SumWeightedMarks = 0;
            SumCredits = 0;
            MaxMark = 0;

            for (i = 0; i < N; i++) {
                SumWeightedMarks += t[i].mark * t[i].credits;
                SumCredits += t[i].credits;
                if (MaxMark < t[i].mark) {
                    MaxMark = t[i].mark;
                }
            }

            avg = (float) SumWeightedMarks / SumCredits;

            printf("Student %s Average: %f and Maximum Mark %d\n", argv[k], avg, MaxMark);
            exit(0);

        }
    }
}