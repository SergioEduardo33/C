//Escreva um programa que leia um arquivo de texto contendo uma lista de números inteiros, armazene-os em um array e utilize o algoritmo de ordenação Bubble Sort para ordenar o array.

//Professor eu fiz o exercício C3 pois não consegui fazer o C8

//biblioteca para entrada e saída de dados
#include <stdio.h>

//criando a função bubble sort
void sg_bubble_sort(int sg_arr[], int sg_n) {
    int sg_i, sg_j, sg_temp; //criando as variaveis
  //montando o bubble sort
    for (sg_i = 0; sg_i < sg_n - 1; sg_i++) {
      //montando o bubble sort
        for (sg_j = 0; sg_j < sg_n - sg_i - 1; sg_j++) {
          //caso  o array na posição j seja maior que ele mesmo +1
            if (sg_arr[sg_j] > sg_arr[sg_j + 1]) {
                sg_temp = sg_arr[sg_j]; //variavel temporaria recebe o array na posição j
                sg_arr[sg_j] = sg_arr[sg_j + 1]; //array na posição j recebe ele +1
                sg_arr[sg_j + 1] = sg_temp; //aray na j recebe a variavel temporaria
            }
        }
    }
}

 //função principal
int main() {
    FILE *sg; //ponteiro para o arquivo
    int sg_arr[100], sg_i, sg_size; //criando variáveis

    sg = fopen("sg_numeros.txt", "r"); //para abrir o arquivo em modo de leirura
   //caso ocorra um erro no arquivo
    if (sg == NULL) {
        printf("Erro ao abrir o arquivo.\n"); //mostra na tela que ocorreu um erro
        return 1; //retorna 1
    }

    sg_i = 0; //ativando a variavel sg_i
  
    //auxilia a montar montar a estrutura do arquivo
    while (fscanf(sg, "%d", &sg_arr[sg_i]) == 1) {
        sg_i++; //variavel sg_i recbe + 1 em cada laço
    }

    sg_size = sg_i; //size recebe i
    fclose(sg); //fecha o arquivo
  
  //função bubble sort sendo aplicada
    sg_bubble_sort(sg_arr, sg_size);

    sg = fopen("sg_numeros_ordenados.txt", "w"); //abre o arquivo no modo de escrita
    //percorre o arquivo
    for (sg_i = 0; sg_i < sg_size; sg_i++) {
        fprintf(sg, "%d\n", sg_arr[sg_i]); //printa a ordem do arquivo
    }

    fclose(sg); //fecha o arquivo
    printf("Arquivo sg_numeros_ordenados.txt ordenado com sucesso!"); //printa que o arquivo foi ordenado com sucesso
    return 0; //encerra a função main
}
