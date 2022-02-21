//
// Created by Raffaele Mura on 18/02/22.
//

float min(float *V, int N){

    float min = V[0];
    int i;

    for(i=1; i<N; i++)
        if(min>V[i]) min = V[i];

    return min;
}