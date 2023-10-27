#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char nome_completo[100];
    int salas[4] = {0}, sala, nota, continuar;
    char *salasTemas[] = {"Olimpiadas", "Tecnologia", "Santos Dumont", "Semana de Arte Moderna"};

    arquivo = fopen("feedback.csv", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    printf("Questionario de Feedback - Museu Multitematico\n");
    printf("----------====================----------\n");

    printf("Digite o seu nome completo: ");
    scanf(" %[^\n]s", nome_completo);

    do {
        printf("Salas Tematicas do nosso museu disponiveis para avaliacao:\n");
        for (int i = 0; i < 4; i++) {
            printf("%d - %s\n", i + 1, salasTemas[i]);
        }

        printf("Escolha as salas tematicas que visitou (1-4): ");
        scanf("%d", &sala);

        if (sala < 1 || sala > 4) {
            printf("Esta sala nao existe. Escolha um numero entre 1 e 4.\n");
        }

        printf("Digite uma nota para a sala tematica escolhida (1-5): ");
        scanf("%d", &nota);

        if (nota < 1 || nota > 5) {
            printf("Esta nota nao existe. Escolha um numero entre 1 e 5.\n");
        }

        salas[sala - 1] = nota;

        printf("Voce visitou outra sala tematica? Se SIM, Gostaria de avaliar ela? (1 - Sim, 0 - Nao): ");
        scanf("%d", &continuar);
    } while (continuar == 1);

    for (int i = 0; i < 4; i++) {
        fprintf(arquivo, "%s,%s,%d\n", nome_completo, salasTemas[i], salas[i]);
    }
    fclose(arquivo);

    printf("O seu feedback foi registrado com sucesso. Muito Obrigado!\n");

    return 0;
}
