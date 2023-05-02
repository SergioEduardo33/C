//Implemente o algoritmo de ordenação Insertion Sort e utilize-o para ordenar um array de structs representando datas.

//biblioteca para entrada e saída de dados
#include <stdio.h>

// Definição da struct para representar datas
struct sg_data {
    int sg_dia; // variavel para representar o dia
    int sg_mes; // variavel para representar o mês
    int sg_ano; // variavel para representar o ano
};

// Função para imprimir um array de datas
void sg_imprimirDatas(struct sg_data arr[], int sg_n) {
  //percorre a struct para acionar o print em seguida
    for (int sg_i = 0; sg_i < sg_n; sg_i++) {
        printf("%02d/%02d/%04d\n", arr[sg_i].sg_dia, arr[sg_i].sg_mes, arr[sg_i].sg_ano); //printa as datas na tela
    }
}

// Função de ordenação Insertion Sort para datas
void sg_insertionSort(struct sg_data arr[], int sg_n) {
  //repete a struct e o while e ajuda a ordenar 
    for (int sg_i = 1; sg_i < sg_n; sg_i++) {
        struct sg_data sg_chave = arr[sg_i]; // variavel para representar a struct
        int sg_j = sg_i - 1; //variavel para usar no while
      //usado para ordenar as datas
        while (sg_j >= 0 && (arr[sg_j].sg_ano > sg_chave.sg_ano ||
               (arr[sg_j].sg_ano == sg_chave.sg_ano && arr[sg_j].sg_mes > sg_chave.sg_mes) ||
               (arr[sg_j].sg_ano == sg_chave.sg_ano && arr[sg_j].sg_mes == sg_chave.sg_mes && arr[sg_j].sg_dia > sg_chave.sg_dia))) {
            arr[sg_j + 1] = arr[sg_j]; //colocando as datas em ordem
            sg_j = sg_j - 1; //diminui 1 da variável no laço
        }
        arr[sg_j + 1] = sg_chave; // array recebe o índice da variavel +1 e recebe a struct
    }
}

int main() {
    // Onde botar as datas desordenadas
    struct sg_data sg_datas[] = {
        {16, 4, 2021}, //data desordenada
        {1, 2, 2022}, //data desordenada
        {11, 8, 2020}, //data desordenada
        {7, 11, 2019}, //data desordenada
        {10, 1, 2023} //data desordenada
    };
    int sg_n = sizeof(sg_datas) / sizeof(sg_datas[0]); //variavel para armazenar a função size of 

    printf("Array de datas desordenadas:\n"); // mostra essa frase na tela
    sg_imprimirDatas(sg_datas, sg_n); //chama a função para imprimir datas

    // Ordenando o array de datas
    sg_insertionSort(sg_datas, sg_n); //aplicando função de ordenação

    printf("\nArray de datas ordenadas:\n"); // mostra essa frase na tela
    sg_imprimirDatas(sg_datas, sg_n); //chama a função para imprimir datas

    return 0; //encerra a função main
}
