//Utilizando o algoritmo de ordenação Bubble Sort, escreva um programa que leia um arquivo de texto contendo nomes e notas de alunos e escreva em outro arquivo a lista de alunos ordenada por nota.

//biblioteca de entrada e saída de dados
#include <stdio.h>
//biblioteca de manipulação de strings
#include <string.h>
// Define o máximo de alunos na lista
#define sg_max_alunos 100 
// Define o tamanho máximo do nome do aluno
#define sg_max_nome 50 

// Função para fazer a troca de posição entre dois elementos
void swap(int *sg_a, int *sg_b) {
    int sg_temp = *sg_a; //estabelencendo o ponteiro
    *sg_a = *sg_b; //variavel a recebe a b
    *sg_b = sg_temp; //variavel b recebe a temporaria
}
//código principal
int main() {
    FILE *sg_arquivoEntrada, *sg_arquivoSaida; //ponteiro de arquivos
    char sg_nome[sg_max_alunos][sg_max_nome]; //variável nome na posição max nome
    int sg_notas[sg_max_alunos];//variável notas na posição max alunos
    int sg_qtdAlunos = 0; //variavel de nota de alunos
    sg_arquivoEntrada = fopen("sg_entrada.txt", "r"); // Abre o arquivo de entrada em modo de leitura
  
  //caso aconteça algum erro
    if (sg_arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n"); //mostra que ocorreu algum erro
        return 1; //retorna 1
    }

    // Lê os nomes e notas dos alunos do arquivo de entrada e armazena em arrays
    while (fscanf(sg_arquivoEntrada, "%s %d", sg_nome[sg_qtdAlunos], &sg_notas[sg_qtdAlunos]) == 2) {
        sg_qtdAlunos++; //variavel da quantidade de alunos recebe + 1 cada vez q roda
    }
    // Realiza o Bubble Sort para ordenar os alunos por nota em ordem crescente
    for (int sg_i = 0; sg_i < sg_qtdAlunos - 1; sg_i++) {
      // Realiza o Bubble Sort para ordenar os alunos por nota em ordem crescente
        for (int sg_j = 0; sg_j < sg_qtdAlunos - sg_i - 1; sg_j++) {
          //estruturando a condição para finalizar o bubble sort
            if (sg_notas[sg_j] > sg_notas[sg_j + 1]) {
                swap(&sg_notas[sg_j], &sg_notas[sg_j + 1]); //fazendo a troca de posição
                char sg_temp[sg_max_nome]; //variavel temporaria
                strcpy(sg_temp, sg_nome[sg_j]); //fazendo copia de dados 
                strcpy(sg_nome[sg_j], sg_nome[sg_j + 1]); //fazendo copia de dados 
                strcpy(sg_nome[sg_j + 1], sg_temp); //fazendo copia de dados 
            }
        }
    }

    // Abre o arquivo de saída em modo de escrita
    sg_arquivoSaida = fopen("sg_saida.txt", "w");
  //caso tenha algum erro
    if (sg_arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída\n"); //mostra na tela que teve algum erro
        return 1; //retorna 1 
    }

    // Escreve a lista de alunos ordenada por nota no arquivo de saída
    for (int sg_i = 0; sg_i < sg_qtdAlunos; sg_i++) {
        fprintf(sg_arquivoSaida, "%s %d\n", sg_nome[sg_i], sg_notas[sg_i]); //printa a lista de alunos
    }

    
    fclose(sg_arquivoEntrada); //fecha o arquivo
    fclose(sg_arquivoSaida); //fecha o arquivo

    printf("Lista de alunos ordenada por nota foi escrita no arquivo de saída.\n"); //printa que a lista foi ordenada

    return 0; //encerra a função main
}
