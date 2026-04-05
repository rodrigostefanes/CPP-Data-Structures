// Copyright [2025] <Rodrigo Stefanes.>

//Given a vector with N entries...

// Returns the maximum value found in the array.
int maximo(int vet[], int N) {
    int j = 0;
    int i = 1;
    while (i < N) {
        if (vet[j] < vet[i]) {
            j = i;
        }
    i = i + 1;
    }
    return vet[j];
}

// Returns the index of the first occurrence of the maximum value.
int posicao(int vet[], int N) {
    int j = 0;
    int i = 1;
    while (i< N) {
        if (vet[j] < vet[i]) {
            j = i;
        }
    i = i + 1;
    }
    return j;
}


// Returns a structure containing both the maximum value and its position.
struct maxpos{
    int max;
    int pos;
};

maxpos maximo_posicao(int vet[], int N) {
    maxpos resposta_maxpos;
    resposta_maxpos.max = maximo(vet, N);
    resposta_maxpos.pos = posicao(vet, N);
    return resposta_maxpos;
}

// Performs an element-wise maximum comparison between two arrays, updating the first in-place.
void maximo_vetores(int vet1[], int vet2[], int N) {
    int i = 0;
    while (i < N) {
        if (vet1[i] < vet2[i]) {
            vet1[i] = vet2[i];
        }
    i = i + 1;
    }
}

// Reverses the order of elements in the array.
void inversao(int vet[], int N) {
    int vetinv[N];
    int i = 0;
    while (i < N) {
        vetinv[i] = vet[N - i - 1];
        i = i + 1;
    }
    i = 0;
    while (i < N) {
        vet[i] = vetinv[i];
        i = i + 1;
    }
}









