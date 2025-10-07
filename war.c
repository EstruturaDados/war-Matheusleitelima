#include "funcoes.h"

int main() {
    srand(time(NULL));

    int qtd;
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &qtd);

    struct Territorio* mapa = (struct Territorio*) calloc(qtd, sizeof(struct Territorio));
    if (mapa == NULL) {
        printf("Falha ao alocar memoria.\n");
        return 1;
    }

    cadastrar(mapa, qtd);

    // Missões
    char* missoes[] = {
        "Conquistar 3 territorios seguidos",
        "Eliminar todas as tropas vermelhas",
        "Dominar 2 territorios com mais de 10 tropas",
        "Ter o dobro de tropas do inimigo",
        "Vencer 3 batalhas consecutivas"
    };
    int totalMissoes = sizeof(missoes) / sizeof(missoes[0]);

    // Missões dos jogadores
    char* missaoJogador1 = (char*) malloc(100 * sizeof(char));
    char* missaoJogador2 = (char*) malloc(100 * sizeof(char));

    atribuirMissao(missaoJogador1, missoes, totalMissoes);
    atribuirMissao(missaoJogador2, missoes, totalMissoes);

    printf("\nMissao do Jogador 1: %s\n", missaoJogador1);
    printf("Missao do Jogador 2: %s\n", missaoJogador2);

    int opcao;
    do {
        mostrar(mapa, qtd);
        printf("\n1 - Atacar\n2 - Verificar Missoes\n3 - Sair\nOpcao: ");
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
        } else if (opcao == 2) {
            if (verificarMissao(missaoJogador1, mapa, qtd)) {
                printf("\nJogador 1 cumpriu sua missao e venceu o jogo!\n");
                break;
            }
            if (verificarMissao(missaoJogador2, mapa, qtd)) {
                printf("\nJogador 2 cumpriu sua missao e venceu o jogo!\n");
                break;
            }
            printf("Nenhum jogador cumpriu a missao ainda.\n");
        }

    } while (opcao != 3);

    liberarMemoria(mapa, missaoJogador1, missaoJogador2);
    printf("\nPrograma encerrado, memoria liberada!\n");

    return 0;
}
