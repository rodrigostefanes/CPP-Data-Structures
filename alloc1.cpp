// Copyright [2026] Rodrigo Stefanes
#include <string>


class Aluno {
 public:
    Aluno() {}  // construtor
    ~Aluno() {}  // destrutor
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


// Creates a dynamically allocated array of Students from arrays of names and IDs.

Aluno *turma(std::string nomes[], int matriculas[], int N) {
    Aluno *t;
    t = new Aluno[N];
    int i = 0;
    while (i < N) {
        (*(t + i)).escreveNome(nomes[i]);
        (*(t + i)).escreveMatricula(matriculas[i]);
        i = i + 1;
    }
    return t;
}

// Creates a new dynamically allocated array by merging two existing student arrays (appending t2 after t1).
Aluno *turmas_uniao(Aluno t1[], Aluno t2[], int N1, int N2) {
    Aluno *tu;
    tu = new Aluno[N1+N2];
    int i = 0;
    while (i < N1) {
        (*(tu + i)).escreveNome((*(t1 + i)).devolveNome());
        (*(tu + i)).escreveMatricula((*(t1 + i)).devolveMatricula());
        i = i + 1;
    }
    i = 0;
    while (i < N2) {
        (*(tu + (i + N1))).escreveNome((*(t2 + i)).devolveNome());
        (*(tu + (i + N1))).escreveMatricula((*(t2 + i)).devolveMatricula());
        i = i + 1;
    }

    return tu;
}

// Splits an existing student array into two new dynamically allocated arrays at the specified index k.
void turmas_divisao(Aluno t[], int k, int N, Aluno **pt1, Aluno **pt2) {
    Aluno *t1 = new Aluno[k];
    Aluno *t2 = new Aluno[N-k];
    int i = 0;
    while (i < k) {
        (*(t1+i)).escreveNome((*(t+i)).devolveNome());
        (*(t1+i)).escreveMatricula((*(t+i)).devolveMatricula());
        i = i + 1;
    }
    i = 0;
    while (i < (N - k)) {
        (*(t2 + i)).escreveNome((*(t + (i + k))).devolveNome());
        (*(t2 + i)).escreveMatricula((*(t + (i + k))).devolveMatricula());
        i = i + 1;
    }
    *pt1 = t1;
    *pt2 = t2;
}
