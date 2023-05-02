//Crie uma função que receba dois arrays de structs representando datas e retorne um novo array com a união dos dois arrays, mantendo a ordenação das datas.

//biblioteca de entrada e saída de dados
#include <stdio.h>
//biblioteca que converte strings
#include <stdlib.h>
// número máximo de números no arquivo
#define sg_max_numeros 100 

// Função de ordenação por seleção
void fa_ordenarPorSelecao(int sg_array[], int sg_tamanho) {
    int sg_i, sg_j, sg_min, sg_temp;
    // percorre o array
    for (sg_i = 0; sg_i < sg_tamanho - 1; sg_i++) {
        sg_min = sg_i; // Índice do menor elemento encontrado até agora
        // laço para procurar o menor elemento a partir da posição i+1
        for (sg_j = sg_i+1; sg_j < sg_tamanho; sg_j++) { 
          //caso o array em uma posição seja menor do que o mesmo em outra posição
            if (sg_array[sg_j] < sg_array[sg_min]) {
                sg_min = sg_j; // a variável sg_min recebe sg_j
            }
        }
        // Trocar o menor elemento encontrado pela posição atual i, se for diferente
        if (sg_min != sg_i) { 
            sg_temp = sg_array[sg_i]; //variavel temporária recebe o array na posição i
            sg_array[sg_i] = sg_array[sg_min]; //o array na posição sg_i recebe o array na posição sg_min
            sg_array[sg_min] = sg_temp; //o array na posição sg_min recebe a variavel temporária
        }
    }
}
//função principal
int main() {
    int sg_array[sg_max_numeros]; // Array para armazenar os números do arquivo
    int sg_tamanho = 0; // Tamanho atual do array
    FILE* sg_arquivo; // Ponteiro para o arquivo
    int sg_numero; // Número lido do arquivo

    
    sg_arquivo = fopen("sg_numeros.txt", "r"); // Abre e lê o arquivo
    //caso ocorra um erro
    if (sg_arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n"); //mostra que ocorreu um erro
        exit(1); //sai do arquivo
    }

   // looping para ler os números do arquivo e armazená-los no array
    while (fscanf(sg_arquivo, "%d", &sg_numero) != EOF && sg_tamanho < sg_max_numeros) { 
        sg_array[sg_tamanho] = sg_numero; //o array na posição de tamanho recebe a variável número
        sg_tamanho++; //tamanho recebe + 1 em cada laço
    }

    fclose(sg_arquivo);   // fecha o arquivo

    fa_ordenarPorSelecao(sg_array, sg_tamanho); // ordenar o array por seleção
   
  printf("Lista única: ");
    for (int i = 0; i < sg_tamanho; i++) { //laço para imprimir cada número da lista
        printf("%d ", sg_array[i]); // Imprimir o array ordenado
    }
    printf("\n"); //para quebrar linha

    return 0; //encerra a função main
}
