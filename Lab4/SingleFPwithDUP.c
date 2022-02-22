//
// Created by Raffaele Mura on 21/02/22.
//

#include <stdio.h>
#include <stdlib.h>


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

    if ((fp = fopen(argv[1], "r")) == NULL) {
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

    printf("\n \n Student %s: Average: %f and Maximum Mark: %d\n\n", argv[1], avg, MaxMark);
    exit(1);
}


