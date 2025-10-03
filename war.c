#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Definição da struct Territorio
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

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

int main() {
    srand(time(NULL));

    int qtd;
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &qtd);

    // alocação dinâmica
    struct Territorio* mapa = (struct Territorio*) calloc(qtd, sizeof(struct Territorio));
    if (mapa == NULL) {
        printf("Falha ao alocar memoria.\n");
        return 1;
    }

    cadastrar(mapa, qtd);

    int opcao;
    do {
        mostrar(mapa, qtd);
        printf("\n1 - Atacar\n2 - Sair\nOpcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int a, d;
            printf("Escolha o numero do atacante: ");
            scanf("%d", &a);
            printf("Escolha o numero do defensor: ");
            scanf("%d", &d);

            if (a < 1 || a > qtd || d < 1 || d > qtd) {
                printf("[ERRO] Territorio invalido!\n");
            } else {
                atacar(&mapa[a - 1], &mapa[d - 1]);
            }
        }

    } while (opcao != 2);

    free(mapa); // libera memória
    printf("\nPrograma encerrado, memoria liberada!\n");
    return 0;
}
