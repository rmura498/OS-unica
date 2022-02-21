//
// Created by Raffaele Mura on 18/02/22.
//

float max(float *V, int N){

    float max = V[0];
    int i;

    for(i=1; i<N; i++)
        if(max<V[i]) max = V[i];

    return max;


}