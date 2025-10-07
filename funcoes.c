#include "funcoes.h"

// Cadastro dos territórios
void cadastrar(struct Territorio* t, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\n--- Cadastro do territorio %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %29[^\n]", t[i].nome);
        printf("Cor do exercito: ");
        scanf(" %9s", t[i].cor);
        printf("Qtd de tropas: ");
        scanf("%d", &t[i].tropas);
    }
}

// Mostra todos os territórios
void mostrar(struct Territorio* t, int qtd) {
    printf("\n===== Territorios =====\n");
    for (int i = 0; i < qtd; i++) {
        printf("[%d] %s | Cor: %s | Tropas: %d\n",
               i + 1, t[i].nome, t[i].cor, t[i].tropas);
    }
}

// Função de ataque
void atacar(struct Territorio* at, struct Territorio* def) {
    if (strcmp(at->cor, def->cor) == 0) {
        printf("\n[ERRO] Nao pode atacar um territorio da mesma cor!\n");
        return;
    }
    if (at->tropas < 2) {
        printf("\n[ERRO] Precisa de pelo menos 2 tropas pra atacar.\n");
        return;
    }

    int dadoAt = rand() % 6 + 1;
    int dadoDef = rand() % 6 + 1;

    printf("\nDados: Atacante %d x Defensor %d\n", dadoAt, dadoDef);

    if (dadoAt > dadoDef) {
        printf(">> Atacante venceu e conquistou o territorio!\n");
        def->tropas = at->tropas / 2;
        strcpy(def->cor, at->cor);
    } else {
        printf(">> Defensor resistiu ao ataque!\n");
        at->tropas--;
    }
}

// Atribui uma missão
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

// Verifica a missão (lógica inicial)
int verificarMissao(char* missao, struct Territorio* mapa, int tamanho) {
    int count = 0;
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(mapa[i].cor, "azul") == 0) count++;
    }
    if (strstr(missao, "Conquistar 3 territorios") != NULL && count >= 3)
        return 1;
    return 0;
}

// Libera memória
void liberarMemoria(struct Territorio* mapa, char* missao1, char* missao2) {
    free(mapa);
    free(missao1);
    free(missao2);
}