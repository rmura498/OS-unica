//
// Created by Raffaele Mura on 18/02/22.
//

float sum(float *V, int N){

    float sum = 0;
    int i;

    for(i=0; i<N; i++)
        sum +=V[i];

    return sum;
}