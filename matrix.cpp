// Copyright [2025] <Rodrigo Stefanes>




// Returns the minimum value found in the MxN matrix.
int minimo(int **mat, int M, int N) {
    int i = 0;
    int j = 0;
    int min = mat[0][0];
    while (i < M) {
        while (j < N) {
            if (min > mat[i][j]) {
                min = mat[i][j];
            }
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
    return min;
}

// Returns the coordinates (row and column) of the first occurrence of the minimum value.
struct coord {
    int x;  // linha
    int y;  // coluna
};

coord coordenada_menor(int **mat, int M, int N) {
    int i = 0;
    int j = 0;
    coord coord_min = {0, 0};
    while (i < M) {
        while (j < N) {
            if (mat[coord_min.x][coord_min.y] > mat[i][j]) {
                coord_min.x = i;
                coord_min.y = j;
            }
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
    return coord_min;
}

// Performs an element-wise minimum comparison between two matrices, updating the first in-place.
void minimo_matrizes(int **mat1, int **mat2, int M, int N) {
    int i = 0;
    int j = 0;
    while (i < M) {
        while (j < N) {
            if (mat1[i][j] > mat2[i][j]) {
                mat1[i][j] = mat2[i][j];
            }
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
}

// Extracts the main diagonal of an NxN square matrix into a new vector.
int *diagonal(int **mat, int N) { 
    int i = 0;
    int *d;
    d = new int[N];
    while (i < N) {
        d[i] = mat[i][i]; // d[i] = *(d+i) = *(*(mat+i)+i)
        i = i + 1;
    }
    return d;
}

// Calculates the sum of each column in the MxN matrix, returning the results in a vector.
int *soma_colunas(int **mat, int M, int N) {
    int i = 0;
    int j = 0;
    int *s;
    s = new int[N];
    while (j < N) {
        int local_sum = 0;
        while ( i < M ) {
            local_sum = local_sum + mat[i][j];
            i = i + 1;
        }
        s[j] = local_sum;
        i = 0;
        j = j + 1;
    }
    return s;
}






