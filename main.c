#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NOME 50
#define NUM_PERGUNTAS 5

// Função para o minijogo Pergunta e Resposta
void perguntaEResposta() {
    char* perguntas[NUM_PERGUNTAS] = {
        "Qual é a capital da França?",
        "Quem pintou a Mona Lisa?",
        "Qual é o maior planeta do Sistema Solar?",
        "Quem escreveu a peça Hamlet?",
        "Em que ano o Brasil foi descoberto?"
    };
    char* alternativas[NUM_PERGUNTAS][4] = {
        {"1. Paris", "2. Londres", "3. Roma", "4. Berlim"},
        {"1. Leonardo da Vinci", "2. Van Gogh", "3. Picasso", "4. Monet"},
        {"1. Marte", "2. Vênus", "3. Júpiter", "4. Saturno"},
        {"1. Shakespeare", "2. Goethe", "3. Dostoievski", "4. Tolstói"},
        {"1. 1500", "2. 1492", "3. 1600", "4. 1450"}
    };
    int respostas[NUM_PERGUNTAS] = {1, 1, 3, 1, 1}; // Respostas corretas

    int i, escolha;

    for(i = 0; i < NUM_PERGUNTAS; i++) {
        printf("\nPergunta %d: %s\n", i+1, perguntas[i]);
        for(int j = 0; j < 4; j++) {
            printf("%s\n", alternativas[i][j]);
        }
        printf("Escolha a resposta (1-4): ");
        scanf("%d", &escolha);

        if(escolha == respostas[i]) {
            printf("Resposta correta!\n");
        } else {
            printf("Resposta incorreta. A resposta correta é: %d\n", respostas[i]);
        }
    }
}

// Função para o minijogo Cobra na Caixa!
void cobraNaCaixa() {
    char* nomes[] = {"Alice", "Bob", "Charlie", "Diana", "Edward", "Fay", "Grace"};
    int numCaixas = 5;
    int cobra, botao;
    int escolha, jogadorAtual;
    char nomeJogador[MAX_NOME];

    srand(time(0));
    cobra = rand() % numCaixas;
    botao = rand() % numCaixas;

    printf("Escolha seu nome:\n");
    for(int i = 0; i < 7; i++) {
        printf("%d. %s\n", i+1, nomes[i]);
    }
    printf("Escolha o numero do jogador (1-7): ");
    int indice;
    scanf("%d", &indice);
    strcpy(nomeJogador, nomes[indice - 1]);

    jogadorAtual = rand() % 2;  // Sorteio de quem começa

    while(1) {
        printf("\n%s, escolha uma caixa (1-5): ", nomeJogador);
        scanf("%d", &escolha);
        escolha--; // Ajuste de índice

        if(escolha == cobra) {
            printf("Você encontrou a cobra! Você perdeu!\n");
            break;
        } else if(escolha == botao) {
            printf("Você encontrou o botão! Você venceu!\n");
            break;
        } else {
            printf("A caixa está vazia.\n");
        }

        // Troca o jogador
        jogadorAtual = 1 - jogadorAtual;
        printf("\nPróximo jogador...\n");
    }
}

// Função para o minijogo Gousmas War
void gousmasWar() {
    int gousmasJogador1 = 2, gousmasJogador2 = 2;
    int furia1[2] = {1, 1}, furia2[2] = {1, 1};
    int escolha, ataque;

    while(gousmasJogador1 > 0 && gousmasJogador2 > 0) {
        printf("\nJogador 1 tem %d Gousmas e Jogador 2 tem %d Gousmas\n", gousmasJogador1, gousmasJogador2);
        printf("Jogador 1, escolha uma Gousma para atacar (1 ou 2): ");
        scanf("%d", &escolha);
        printf("Jogador 2, escolha uma Gousma para atacar (1 ou 2): ");
        scanf("%d", &ataque);

        // Ataque
        if(furia1[escolha - 1] > furia2[ataque - 1]) {
            furia2[ataque - 1] += furia1[escolha - 1];
            if(furia2[ataque - 1] > 5) {
                gousmasJogador2--;
                printf("Jogador 2 perdeu uma Gousma!\n");
            }
        } else {
            furia1[escolha - 1] += furia2[ataque - 1];
            if(furia1[escolha - 1] > 5) {
                gousmasJogador1--;
                printf("Jogador 1 perdeu uma Gousma!\n");
            }
        }
    }

    if(gousmasJogador1 == 0) {
        printf("Jogador 2 venceu!\n");
    } else {
        printf("Jogador 1 venceu!\n");
    }
}

// Função para mostrar o menu principal
void menu() {
    int opcao;
    do {
        printf("\nMenu Principal:\n");
        printf("1. Pergunta e Resposta\n");
        printf("2. Cobra na Caixa!\n");
        printf("3. Gousmas War\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                perguntaEResposta();
                break;
            case 2:
                cobraNaCaixa();
                break;
            case 3:
                gousmasWar();
                break;
            case 4:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 4);
}

int main() {
    menu();
    return 0;
}