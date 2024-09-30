#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char palavra[16];
    int frequencia;
    struct No* esquerda;
    struct No* direita;
}No;

No* criaNo(char* palavra) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->palavra, palavra);
    novoNo->frequencia = 1;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void insereNo(No** raiz, char* palavra) {
    if (*raiz == NULL) {
        *raiz = criaNo(palavra);
    } else {
        int comparacao = strcmp(palavra, (*raiz)->palavra);
        if (comparacao < 0) {
            insereNo(&((*raiz)->esquerda), palavra);
        } else if (comparacao > 0) {
            insereNo(&((*raiz)->direita), palavra);
        } else {
            (*raiz)->frequencia++;
        }
    }
}

void exibeArvore(No* raiz) {
    if (raiz != NULL) {
        exibeArvore(raiz->esquerda);
        printf("%s (%d)\n", raiz->palavra, raiz->frequencia);
        exibeArvore(raiz->direita);
    }
}

void processaPalavras(char* str[]) {
    No* raiz = NULL;
    int i = 0;
    while (str[i][0] != '\0') {
        insereNo(&raiz, str[i]);
        i++;
    }
    exibeArvore(raiz);
}

int main() {
    char* palavras[] = {
    "carro", "navio", "carro", "aviao", "carro", "camelo", "carro", "motocicleta", "carro","navio", "aviao", "carro", "navio", "\0"
    };
    processaPalavras(palavras);
    return 0;
}