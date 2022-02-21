//
// Created by Raffaele Mura on 18/02/22.
//

#include <stdio.h> // with <> the compiler looks in standard libraries of the OS
#include "./statV.h" // with "" it searches in the directory that is written

int main(void) {

    int N;
    float V[100];
    int i;

    printf("Type the number of elements of the vector");
    scanf("%d",&N);

    for(i=0; i<N; i++) {
        printf("Type the %d-th element: ", i);
        scanf("%f", &V[i]);
    }

    printf("The max value of V is %f\n ", max(V, N));
    printf("The min value of V is %f\n ", min(V, N));
    printf("The avg value of V is %f\n ", avg(V, N));
    printf("The sum of the values of V is %f\n ", sum(V, N));

}
