#include <stdio.h>
#include <stdlib.h>

float* read_array(int *tamanho) {
    scanf("%d", tamanho);

    float *vetor = (float*) malloc(*tamanho * sizeof(float));

    if (vetor != NULL) {
        for (int i = 0; i < *tamanho; i++) {
            scanf("%f", &vetor[i]);
        }
    }

    return vetor;
}

void free_array(float *vetor) {
    if (vetor != NULL) {
        free(vetor);
    }
}