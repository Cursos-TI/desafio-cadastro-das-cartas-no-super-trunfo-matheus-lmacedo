#include <stdio.h>
#include <string.h> // Necessário para usar string (array de caracteres)

int main() {
    int opcao;
    int carta = 1;
    
    // Definindo a estrutura para armazenar os dados das cartas
    struct Carta {
        char estado[3]; // String para representar o estado
        char codigo[3]; // Código da carta (letra + número)
        char nome[30];  // Nome da cidade
        int populacao;  // População (int)
        float area;     // Área (float)
        float pib;      // PIB (float)
        int pontosturisticos; // Número de pontos turísticos (int)
        float densidadepopulacional; // Densidade populacional
        float pibpercapita; // PIB per capita
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
                scanf("%s", cartaAtual->estado); // Usando string para estado

                printf("Insira o código da carta com a LETRA usada anteriormente (01 a 04) ex: A01 \n");
                scanf("%s", cartaAtual->codigo); // Usando string para código

                printf("Insira o NOME da CIDADE: \n");
                scanf(" %[^\n]s", cartaAtual->nome); // Usando string para nome

                printf("Insira a quantidade de HABITANTES (Número exato sem pontos ou vírgula): \n");
                scanf("%d", &cartaAtual->populacao); // População (int)

                printf("Insira a área da cidade em km²: \n");
                scanf("%f", &cartaAtual->area); // Área (float)

                printf("Insira o PIB (PRODUTO INTERNO BRUTO) da cidade (Número exato sem pontos ou vírgula): \n");
                scanf("%f", &cartaAtual->pib); // PIB (float)

                printf("Insira a quantidade de pontos turísticos da cidade: \n");
                scanf("%d", &cartaAtual->pontosturisticos); // Número de pontos turísticos (int)

                // Calculando densidade populacional e PIB per capita
                cartaAtual->densidadepopulacional = cartaAtual->populacao / cartaAtual->area;
                cartaAtual->pibpercapita = cartaAtual->pib / cartaAtual->populacao;

                // Exibindo os atributos da carta
                printf("** Carta criada. Atributos da carta: **\n");
                printf("-- Carta: %d\n", carta);
                printf("-- Código: %s\n", cartaAtual->codigo);
                printf("-- Nome da cidade: %s\n", cartaAtual->nome);
                printf("-- População: %d habitantes\n", cartaAtual->populacao);
                printf("-- Área em km²: %.0f km²\n", cartaAtual->area);
                printf("-- PIB (PRODUTO INTERNO BRUTO): %.2f milhões/bilhões/trilhões..\n", cartaAtual->pib);
                printf("-- Pontos turísticos: %d\n", cartaAtual->pontosturisticos);
                printf("-- Densidade populacional: %.2f hab/km²..\n", cartaAtual->densidadepopulacional);
                printf("-- PIB per capita: %.2f reais..\n", cartaAtual->pibpercapita);

                if (carta == 1) {
                    printf("-- Criação da outra carta -- \n");
                } else {
                    printf("** ## Criação concluída ## ** \n");

                    // Escolhendo o atributo para comparação
                    int atributo;
                    printf("Escolha o atributo para comparação:\n");
                    printf("1. População\n");
                    printf("2. Área\n");
                    printf("3. PIB\n");
                    printf("4. Densidade Populacional\n");
                    printf("5. PIB per Capita\n");
                    printf("Escolha uma opção (1-5): \n");
                    scanf("%d", &atributo);

                    switch (atributo) {
                        case 1: // Comparação de População
                            printf("\n** Comparação de cartas (Atributo: População): **\n");
                            printf("Carta 1 - %s: %d habitantes\n", carta1.nome, carta1.populacao);
                            printf("Carta 2 - %s: %d habitantes\n", carta2.nome, carta2.populacao);
                            if (carta1.populacao > carta2.populacao) {
                                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
                            } else if (carta1.populacao < carta2.populacao) {
                                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
                            } else {
                                printf("Resultado: Empate!\n");
                            }
                            break;
                        case 2: // Comparação de Área
                            printf("\n** Comparação de cartas (Atributo: Área): **\n");
                            printf("Carta 1 - %s: %.2f km²\n", carta1.nome, carta1.area);
                            printf("Carta 2 - %s: %.2f km²\n", carta2.nome, carta2.area);
                            if (carta1.area > carta2.area) {
                                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
                            } else if (carta1.area < carta2.area) {
                                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
                            } else {
                                printf("Resultado: Empate!\n");
                            }
                            break;
                        case 3: // Comparação de PIB
                            printf("\n** Comparação de cartas (Atributo: PIB): **\n");
                            printf("Carta 1 - %s: %.2f bilhões\n", carta1.nome, carta1.pib);
                            printf("Carta 2 - %s: %.2f bilhões\n", carta2.nome, carta2.pib);
                            if (carta1.pib > carta2.pib) {
                                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
                            } else if (carta1.pib < carta2.pib) {
                                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
                            } else {
                                printf("Resultado: Empate!\n");
                            }
                            break;
                        case 4: // Comparação de Densidade Populacional
                            printf("\n** Comparação de cartas (Atributo: Densidade Populacional): **\n");
                            printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nome, carta1.densidadepopulacional);
                            printf("Carta 2 - %s: %.2f hab/km²\n", carta2.nome, carta2.densidadepopulacional);
                            if (carta1.densidadepopulacional < carta2.densidadepopulacional) { // Menor densidade vence
                                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
                            } else if (carta1.densidadepopulacional > carta2.densidadepopulacional) {
                                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
                            } else {
                                printf("Resultado: Empate!\n");
                            }
                            break;
                        case 5: // Comparação de PIB per Capita
                            printf("\n** Comparação de cartas (Atributo: PIB per Capita): **\n");
                            printf("Carta 1 - %s: %.2f reais\n", carta1.nome, carta1.pibpercapita);
                            printf("Carta 2 - %s: %.2f reais\n", carta2.nome, carta2.pibpercapita);
                            if (carta1.pibpercapita > carta2.pibpercapita) {
                                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
                            } else if (carta1.pibpercapita < carta2.pibpercapita) {
                                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
                            } else {
                                printf("Resultado: Empate!\n");
                            }
                            break;
                        default:
                            printf("Opção inválida! Tente novamente.\n");
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
