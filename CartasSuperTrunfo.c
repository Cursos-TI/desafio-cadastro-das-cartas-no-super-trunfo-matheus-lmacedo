#include <stdio.h>

int main() {
    int opcao;
    int carta = 1;
    
    // Definindo a estrutura para armazenar os dados das cartas
    struct Carta {
        char estado;
        char codigo[3];
        char nome[30];
        int pontosturisticos;
        float populacao, area, pib, densidadepopulacional, pibpercapita, superPoder;
    };
    
    // Criando duas cartas
    struct Carta carta1, carta2;

    printf("** ## Bem-vindo ao Super Trunfo de Países! ## **\n");
    printf("1. Iniciar jogo\n");
    printf("2. Informações\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: \n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Iniciando jogo...\n");
            printf("** Super Trunfo de Países **\n");
            printf("-- Criação das cartas -- \n");

            // Criação da primeira carta
            for (carta = 1; carta <= 2; carta++) {
                struct Carta* cartaAtual = (carta == 1) ? &carta1 : &carta2;

                printf("Insira uma letra para representar o ESTADO (de A até H): \n");
                scanf(" %c", &cartaAtual->estado);

                printf("Insira o código da carta com a LETRA usada anteriormente (01 a 04) ex: A01 \n");
                scanf("%s", cartaAtual->codigo);

                printf("Insira o NOME da CIDADE: \n");
                scanf(" %[^\n]s", cartaAtual->nome);

                printf("Insira a quantidade de HABITANTES (Número exato sem pontos ou vírgula): \n");
                scanf("%f", &cartaAtual->populacao);

                printf("Insira a área da cidade em km²: \n");
                scanf("%f", &cartaAtual->area);

                printf("Insira o PIB (PRODUTO INTERNO BRUTO) da cidade (Número exato sem pontos ou vírgula): \n");
                scanf("%f", &cartaAtual->pib);

                printf("Insira a quantidade de pontos turísticos da cidade: \n");
                scanf("%d", &cartaAtual->pontosturisticos);

                // Calculando densidade populacional e PIB per capita
                cartaAtual->densidadepopulacional = cartaAtual->populacao / cartaAtual->area;
                cartaAtual->pibpercapita = cartaAtual->pib / cartaAtual->populacao;

                // Calculando o Super Poder
                cartaAtual->superPoder = (float)(cartaAtual->populacao + cartaAtual->area + cartaAtual->pib + cartaAtual->pontosturisticos + cartaAtual->pibpercapita + 1.0 / cartaAtual->densidadepopulacional);

                // Exibindo os atributos da carta
                printf("** Carta criada. Atributos da carta: **\n");
                printf("-- Carta: %d\n", carta);
                printf("-- Código: %s\n", cartaAtual->codigo);
                printf("-- Nome da cidade: %s\n", cartaAtual->nome);
                printf("-- População: %.0f milhões/bilhões/trilhões.. de habitantes\n", cartaAtual->populacao);
                printf("-- Área em km²: %.0f km²\n", cartaAtual->area);
                printf("-- PIB (PRODUTO INTERNO BRUTO): %.0f milhões/bilhões/trilhões..\n", cartaAtual->pib);
                printf("-- Pontos turísticos: %d\n", cartaAtual->pontosturisticos);
                printf("-- Densidade populacional: %.2f hab/km²..\n", cartaAtual->densidadepopulacional);
                printf("-- PIB per capita: %.2f reais..\n", cartaAtual->pibpercapita);
                printf("-- Super Poder (Soma de todos os atributos): %f\n", cartaAtual->superPoder);

                if (carta == 1) {
                    printf("-- Criação da outra carta -- \n");
                } else {
                    printf("** ## Criação concluída ## ** \n");
                    printf("## Deseja comparar as cartas? ##\n");
                    printf("1. Sim\n");
                    printf("2. Não\n");
                    scanf("%d", &opcao);

                    switch (opcao) {
                        case 1: {
                            // Comparando as cartas
                            int pontosCarta1 = 0, pontosCarta2 = 0;

                            if (carta1.populacao > carta2.populacao) pontosCarta1++;
                            else if (carta1.populacao < carta2.populacao) pontosCarta2++;

                            if (carta1.area > carta2.area) pontosCarta1++;
                            else if (carta1.area < carta2.area) pontosCarta2++;

                            if (carta1.pib > carta2.pib) pontosCarta1++;
                            else if (carta1.pib < carta2.pib) pontosCarta2++;

                            if (carta1.pontosturisticos > carta2.pontosturisticos) pontosCarta1++;
                            else if (carta1.pontosturisticos < carta2.pontosturisticos) pontosCarta2++;

                            if (carta1.densidadepopulacional > carta2.densidadepopulacional) pontosCarta2++;
                            else if (carta1.densidadepopulacional < carta2.densidadepopulacional) pontosCarta1++;

                            if (carta1.pibpercapita > carta2.pibpercapita) pontosCarta1++;
                            else if (carta1.pibpercapita < carta2.pibpercapita) pontosCarta2++;

                            if (carta1.superPoder > carta2.superPoder) pontosCarta1++;
                            else if (carta1.superPoder < carta2.superPoder) pontosCarta2++;

                            printf("\n** Comparação de Cartas **\n");
                            printf("População: Carta 1 venceu (%d)\n", carta1.populacao > carta2.populacao);
                            printf("Área: Carta 1 venceu (%d)\n", carta1.area > carta2.area);
                            printf("PIB: Carta 1 venceu (%d)\n", carta1.pib > carta2.pib);
                            printf("Pontos Turísticos: Carta 1 venceu (%d)\n", carta1.pontosturisticos > carta2.pontosturisticos);
                            printf("Densidade Populacional: Carta 2 venceu (%d)\n", carta2.densidadepopulacional > carta1.densidadepopulacional);
                            printf("PIB per Capita: Carta 1 venceu (%d)\n", carta1.pibpercapita > carta2.pibpercapita);
                            printf("Super Poder: Carta 1 venceu (%d)\n", carta1.superPoder > carta2.superPoder);

                            if (pontosCarta1 > pontosCarta2) {
                                printf("\n** Carta 1 venceu a comparação! **\n");
                            } else if (pontosCarta2 > pontosCarta1) {
                                printf("\n** Carta 2 venceu a comparação! **\n");
                            } else {
                                printf("\n** Empate! **\n");
                            }

                            break;
                        }

                        default:
                            break;
                    }
                }
            }
            break;

        case 2:
            printf("** ## Informações ## **\n");
            printf("1. A combinação da letra do estado e o número da cidade define o código da carta (por exemplo, A01, A02, B01, B02).\n");
            printf("2. Você poderá criar apenas 2 cartas e realizar a comparação de seus atributos.\n");
            printf("** ## Fim ## **");
            break;

        case 3:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.");
            break;
    }

    return 0;
}
