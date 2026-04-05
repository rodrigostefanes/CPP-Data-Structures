// Copyright [2026] Rodrigo Stefanes
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

//Implementing a stack

namespace structures {

template<typename T>
//! CLASSE PILHA
class ArrayStack {
 public:
    //! construtor simples
    ArrayStack();
    //! construtor com parametro tamanho
    explicit ArrayStack(std::size_t max);
    //! destrutor
    ~ArrayStack();
    //! metodo empilha
    void push(const T& data);
    //! metodo desempilha
    T pop();
    //! metodo retorna o topo
    T& top();
    //! metodo limpa pilha
    void clear();
    //! metodo retorna tamanho
    std::size_t size();
    //! metodo retorna capacidade maxima
    std::size_t max_size();
    //! verifica se esta vazia
    bool empty();
    //! verifica se esta cheia
    bool full();

 private:
    T* contents;
    int top_;
    std::size_t max_size_;

    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif


template<typename T>
structures::ArrayStack<T>::ArrayStack() {
    max_size_ = DEFAULT_SIZE;
    contents = new T[max_size_];
    top_ = -1;
    //Apesar de top_ ser private, eu posso acessar ele dentro da minha classe
}

template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max) {
    max_size_ = max;
    contents = new T[max_size_];
    top_ = -1;
}

template<typename T>
structures::ArrayStack<T>::~ArrayStack() {
    delete [] contents;
}

template<typename T>
void structures::ArrayStack<T>::push(const T& data) {
    if (full()) {
        throw std::out_of_range("pilha cheia");
    } else {
        top_ = top_ + 1;
        contents[top_] = data;
        // Aqui seria verdade que top() == contents[top_]; (supondo que top() já esteja bem definido, claro)
    }
}

template<typename T>
T structures::ArrayStack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("pilha vazia");
    } else {
        T p;
        p = contents[top_];
        top_ = top_ - 1;
        return p;
    }
}

template<typename T>
T& structures::ArrayStack<T>::top() {
    T& t = contents[top_];
    return t;
}

template<typename T>
void structures::ArrayStack<T>::clear() {
    top_ = -1;
}

template<typename T>
std::size_t structures::ArrayStack<T>::size() {
    int s;
    s = top_ + 1;
    return s;
}

template<typename T>
std::size_t structures::ArrayStack<T>::max_size() {
    int m;
    m = 10u;
    return m;
}

template<typename T>
bool structures::ArrayStack<T>::empty() {
    if (top_ == -1) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool structures::ArrayStack<T>::full() {
    if ((top_ + 1) == static_cast<int>(max_size_)) {
        return true;
    } else {
        return false;
    }
}
