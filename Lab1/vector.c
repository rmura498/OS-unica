//
// Created by Raffaele Mura on 18/02/22.
//

#include <stdio.h>

float max(float *V, int N);
float min(float *V, int N);
float sum(float *V, int N);
float avg(float *V, int N);

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

float max(float *V, int N){

    float max = V[0];
    int i;

    for(i=1; i<N; i++)
        if(max<V[i]) max = V[i];

    return max;


}

float min(float *V, int N){

    float min = V[0];
    int i;

    for(i=1; i<N; i++)
        if(min>V[i]) min = V[i];

    return min;
}

float sum(float *V, int N){

    float sum = 0;
    int i;

    for(i=0; i<N; i++)
        sum +=V[i];

    return sum;
}

float avg(float *V, int N){
    return sum(V,N)/N;
}