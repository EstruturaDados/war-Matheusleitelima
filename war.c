#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    
    struct Territorio territorios[5];
    int i;

    printf("Sistema de Cadastro de Territorios\n\n");

    // Laço para cadastro dos 5 territórios
    for (i = 0; i < 5; i++) {
        printf("Cadastro do territorio %d:\n", i + 1);

        printf("Digite o nome do territorio: ");
        scanf(" %29[^\n]", territorios[i].nome);

        
        printf("Digite a cor do exercito: ");
        scanf(" %9s", territorios[i].cor);

        
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Exibição dos dados 
    printf("\nTerritorios cadastrados\n");
    for (i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf(" Nome: %s\n", territorios[i].nome);
        printf(" Cor do exercito: %s\n", territorios[i].cor);
        printf(" Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}
