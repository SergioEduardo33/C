//Utilizando o algoritmo de ordenação Insertion Sort, escreva um programa que leia um arquivo de texto contendo nomes e notas de alunos e escreva em outro arquivo a lista de alunos ordenada por nota.

//Biblioteca para entrada  e saída de dados
#include <stdio.h>
//Biblioteca para manipulação de strings
#include <string.h>
// Define o máximo de alunos na lista
#define sg_max_alunos 100 
// Define o tamanho máximo do nome do aluno
#define sg_max_nome 50 

// Função para fazer a troca de posição entre dois elementos
void swap(char sg_a[], char sg_b[]) {
    char sg_temp[sg_max_nome]; //criando uma variavel temporaria
    strcpy(sg_temp, sg_a); //copiando as informações de uma variavel e passando pra outra
    strcpy(sg_a, sg_b); //copiando as informações de uma variavel e passando pra outra
    strcpy(sg_b, sg_temp); //copiando as informações de uma variavel e passando pra outra
}

int main() {
    FILE *arquivoEntrada, *arquivoSaida; //ponteiro para a entrada e saída de arquivos
    char sg_nome[sg_max_alunos][sg_max_nome]; //variavel nome que está na posição max_nome e max_alunos
    int sg_notas[sg_max_alunos]; //variavel notas está na posição de max_alunos
    int sg_qtdAlunos = 0; //criando a variavel de quantidade de alunos e ativando ela

    // Abre o arquivo de entrada em modo de leitura
    arquivoEntrada = fopen("sg_entrada.txt", "r");
    //caso ocorra algum erro na abertura do arquivo
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n"); //mostra na tela que deu um erro
        return 1; //retorna 1
    }

    // Lê os nomes e notas dos alunos do arquivo de entrada e armazena em arrays
    while (fscanf(arquivoEntrada, "%s %d", sg_nome[sg_qtdAlunos], &sg_notas[sg_qtdAlunos]) == 2) {
        sg_qtdAlunos++; //cada laço acrescenta 1 na variavel quantidade de alunos
    }

    // Realiza o Insertion Sort para ordenar os alunos por nota em ordem crescente
    for (int sg_i = 1; sg_i < sg_qtdAlunos; sg_i++) {
        int sg_chave = sg_notas[sg_i]; //armazena as nota em uma variável
        char sg_chaveNome[sg_max_nome]; //variavel recebendo a posição max_nome
        strcpy(sg_chaveNome, sg_nome[sg_i]); //fazendo uma copia 
        int sg_j = sg_i - 1; //variavel j recebe i - 1
      // continua o insertion sort
        while (sg_j >= 0 && sg_notas[sg_j] > sg_chave) {
            sg_notas[sg_j + 1] = sg_notas[sg_j]; //notas recebe a outra variavel notas  a posição j
            strcpy(sg_nome[sg_j + 1], sg_nome[sg_j]); //realiza uma copia 
            sg_j--; //em cada laço j perde 1
        }
        sg_notas[sg_j + 1] = sg_chave; //variavel notas recebe a variavel chave
        strcpy(sg_nome[sg_j + 1], sg_chaveNome); //realiza uma copia 
    }

    // Abre o arquivo de saída em modo de escrita
    arquivoSaida = fopen("sg_saida.txt", "w");
    //caso ocorra algum erro na abertura do arquivo
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída\n"); //mostra na tela que deu um erro
        return 1; //retorna 1
    }

    // Escreve a lista de alunos ordenada por nota no arquivo de saída
    for (int sg_i = 0; sg_i < sg_qtdAlunos; sg_i++) {
        fprintf(arquivoSaida, "%s %d\n", sg_nome[sg_i], sg_notas[sg_i]); //printa o nome e a nota ap lado
    }

   
    fclose(arquivoEntrada); // Fecha os arquivos
    fclose(arquivoSaida); // Fecha os arquivos

    printf("Lista de alunos ordenada por nota foi escrita no arquivo de saída.\n"); //avisa que a lista foi escrita no arquivo de saída

    return 0; //encerra a função main
}
