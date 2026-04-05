//Copyright [2026] Rodrigo Stefanes
#include "./array_stack.h"

// Write a function that takes a program snippet (as a string) and verifies if all curly braces '{' and '}' are correctly nested.

bool verificaChaves(std::string trecho_programa) {
    bool resposta = true;
    int  tamanho  = trecho_programa.length();
    structures::ArrayStack<char> pilha(500);
    
    for (int i = 0; i < tamanho; i++) {
        if (trecho_programa[i] == '{') {
            pilha.push(trecho_programa[i]);
        }
        if (trecho_programa[i] == '}') {
            if (pilha.empty()) {
                resposta = false;
            }
            else {
                pilha.pop();
            }
        }
    }
    if (resposta == true) {
        if (pilha.empty()) {
            resposta = true;
        }
        else {
            resposta = false;
        }
    }
    return resposta;
}