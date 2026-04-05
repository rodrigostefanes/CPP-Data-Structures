// Copyright [2026] Rodrigo Stefanes
#include <string>


class Aluno {
 public:
    Aluno() {}  // constructor
    ~Aluno() {}  // destructor
    std::string devolveNome() {
        return nome;
    }
    int devolveMatricula() {
        return matricula;
    }
    void escreveNome(std::string nome_) {
        nome = nome_;
    }
    void escreveMatricula(int matricula_) {
        matricula = matricula_;
    }
 private:
    std::string nome;
    int matricula;
};

// Creates a new dynamically allocated array containing only students with IDs greater than or equal to menor_matr.
Aluno *turma_filtra(Aluno t[], int N, int menor_matr) {
    Aluno *tf;
    tf = nullptr; 
    int i = 0;
    int j = 0;
    while (i < N) {
        if ((*(t + i)).devolveMatricula() < menor_matr) { 
        }
        else {
            j = j + 1;
        }
        i = i + 1;
    }
    tf = new Aluno[j];
    i = 0;
    int k = 0;
    while (i < N) {
        if ((*(t + i)).devolveMatricula() < menor_matr) {
        }
        else {
            (*(tf+k)).escreveMatricula((*(t+i)).devolveMatricula());
            (*(tf+k)).escreveNome((*(t+i)).devolveNome());
            k = k + 1;
        }
        i = i + 1;
    }

    return tf;
}
// Returns an array of 26 integers representing the count of students whose names start with each letter from A to Z.
int *turma_conta(Aluno t[], int N) {
    int *c;
    c = new int[26]();
    char alfabeto[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K' , 'L' , 'M' , 'N', 'O', 'P', 'Q', 'R', 'S', 'T','U', 'V','W','X','Y', 'Z'};
    int i = 0; //runs through the students
    int j = 0; //runs through the alphabet
    while (i < N) {
        while (j < 26) {
            if ((*(t+i)).devolveNome()[0] == alfabeto[j]) {
                *(c+j) = *(c+j) + 1;
            }
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
    return c;
}

// Creates an array of 26 pointers, each pointing to a dynamically allocated sub-array of students grouped by their name's initial letter.
Aluno **grupos_por_iniciais(Aluno t[], int N) {
    Aluno **g;
    g = new Aluno*[26]; 
    char alfabeto[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K' , 'L' , 'M' , 'N', 'O', 'P', 'Q', 'R', 'S', 'T','U', 'V','W','X','Y', 'Z'};
    int i = 0; 
    int j = 0; 
    int k = 0;
    int *c = turma_conta(t, N); 
    while (i < 26) {   
        *(g + i) = new Aluno[*(c + i)]; 
        while (j < N) {  //Runs through the students
            if ((*(t + j)).devolveNome()[0] == alfabeto[i]) { //Compare if the student names starts with the fixed letter 
                (*(*(g + i) + k)).escreveNome((*(t + j)).devolveNome());
                (*(*(g + i) + k)).escreveMatricula((*(t + j)).devolveMatricula()); 
                k = k + 1; //store the information of how many names have been put into the group 
            }
            j = j + 1;
        }
        k = 0;
        j = 0;
        i = i + 1;
    }
    delete[] c;
    return g;
}
