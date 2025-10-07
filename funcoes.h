#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura de Território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Protótipos de funções
void cadastrar(struct Territorio* t, int qtd);
void mostrar(struct Territorio* t, int qtd);
void atacar(struct Territorio* at, struct Territorio* def);
void atribuirMissao(char* destino, char* missoes[], int totalMissoes);
int verificarMissao(char* missao, struct Territorio* mapa, int tamanho);
void liberarMemoria(struct Territorio* mapa, char* missao1, char* missao2);

#endif