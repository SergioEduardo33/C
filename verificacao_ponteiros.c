//Bibliotecas usadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar uma palavra e sua frequência
typedef struct {
    char palavra[50];
    int frequencia;
} Palavra;

// Função para comparar duas palavras por tamanho em número de caracteres
int compararPorTamanho(const void *a, const void *b) {
    Palavra *palavraA = (Palavra *)a;
    Palavra *palavraB = (Palavra *)b;
    return strlen(palavraA->palavra) - strlen(palavraB->palavra);
}

// Função para comparar duas palavras por frequência no arquivo
int compararPorFrequencia(const void *a, const void *b) {
    Palavra *palavraA = (Palavra *)a;
    Palavra *palavraB = (Palavra *)b;
    return palavraA->frequencia - palavraB->frequencia;
}

// Função para verificar se uma palavra está na lista e retornar sua frequência
int verificarPalavra(const char *palavra, Palavra *lista, int tamanhoLista) {
    for (int i = 0; i < tamanhoLista; i++) {
        if (strcmp(lista[i].palavra, palavra) == 0) {
            return lista[i].frequencia;
        }
    }
    return 0;
}

// Função para criar o arquivo com as palavras e suas frequências
void criarArquivoPalavras(const char *nomeArquivo, Palavra *lista, int tamanhoLista) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    for (int i = 0; i < tamanhoLista; i++) {
        fprintf(arquivo, "%s: %d\n", lista[i].palavra, lista[i].frequencia);
    }

    fclose(arquivo);
    printf("Arquivo criado com sucesso.\n");
}

// Função para inverter a ordem das palavras no arquivo criado
void inverterOrdemPalavras(Palavra *lista, int tamanhoLista) {
    int inicio = 0;
    int fim = tamanhoLista - 1;
    while (inicio < fim) {
        Palavra temp = lista[inicio];
        lista[inicio] = lista[fim];
        lista[fim] = temp;
        inicio++;
        fim--;
    }
}

//Função principal 
int main() {
    int opcao;
    char nomeArquivo[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    // Abrir o arquivo para leitura
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    // Contar a quantidade total de palavras no arquivo
    int totalPalavras = 0;
    char palavra[50];
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        totalPalavras++;
    }

    // Voltar ao início do arquivo
    rewind(arquivo);

    // Criar a lista de palavras
    Palavra *listaPalavras = malloc(totalPalavras * sizeof(Palavra));
    int tamanhoLista = 0;

    // Preencher a lista de palavras e suas frequências
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        int frequencia = verificarPalavra(palavra, listaPalavras, tamanhoLista);
        if (frequencia == 0) {
            strcpy(listaPalavras[tamanhoLista].palavra, palavra);
            listaPalavras[tamanhoLista].frequencia = 1;
            tamanhoLista++;
        } else {
            frequencia++;
            for (int i = 0; i < tamanhoLista; i++) {
                if (strcmp(listaPalavras[i].palavra, palavra) == 0) {
                    listaPalavras[i].frequencia = frequencia;
                    break;
                }
            }
        }
    }
  //Fecha o arquivo
    fclose(arquivo);
  //Aqui mostra o menu para a escolha de opções
    do{
      printf("Escolha uma opcao:\n");
    printf("1) Verificar se uma palavra esta na lista\n");
    printf("2) Listar palavras por ordem crescente de tamanho\n");
    printf("3) Listar palavras por ordem decrescente de tamanho\n");
    printf("4) Listar palavras por ordem crescente de frequencia\n");
    printf("5) Listar palavras por ordem decrescente de frequencia\n");
    printf("6) Criar arquivo com palavras e frequencias\n");
    printf("7) Inverter ordem das palavras\n");
    printf("0) Sair\n");
    printf("Digite o numero da opcao: ");
    scanf("%d", &opcao);
// O que acontece caso escolha cada opção
    switch (opcao) {
        case 1: {
            char palavraProcurada[50];
            printf("Digite a palavra a ser procurada: ");
            scanf("%s", palavraProcurada);
            int frequencia = verificarPalavra(palavraProcurada, listaPalavras, tamanhoLista);
            if (frequencia > 0) {
                printf("A palavra '%s' aparece %d vez(es).\n", palavraProcurada, frequencia);
            } else {
                printf("A palavra '%s' nao esta na lista.\n", palavraProcurada);
            }
            break;
        }
        case 2: {
            qsort(listaPalavras, tamanhoLista, sizeof(Palavra), compararPorTamanho);
            printf("Palavras por ordem crescente de tamanho:\n");
            for (int i = 0; i < tamanhoLista; i++) {
                printf("%s - %d\n", listaPalavras[i].palavra, listaPalavras[i].frequencia);
            }
            break;
        }
        case 3: {
            qsort(listaPalavras, tamanhoLista, sizeof(Palavra), compararPorTamanho);
            printf("Palavras por ordem decrescente de tamanho:\n");
            for (int i = tamanhoLista - 1; i >= 0; i--) {
                printf("%s - %d\n", listaPalavras[i].palavra, listaPalavras[i].frequencia);
            }
            break;
        }
        case 4: {
            qsort(listaPalavras, tamanhoLista, sizeof(Palavra), compararPorFrequencia);
            printf("Palavras por ordem crescente de frequencia:\n");
            for (int i = 0; i < tamanhoLista; i++) {
                printf("%s - %d\n", listaPalavras[i].palavra, listaPalavras[i].frequencia);
            }
            break;
        }
        case 5: {
            qsort(listaPalavras, tamanhoLista, sizeof(Palavra), compararPorFrequencia);
            printf("Palavras por ordem decrescente de frequencia:\n");
            for (int i = tamanhoLista - 1; i >= 0; i--) {
                printf("%s - %d\n", listaPalavras[i].palavra, listaPalavras[i].frequencia);
            }
            break;
        }
        case 6: {
            char nomeArquivoPalavras[100];
            printf("Digite o nome do arquivo de palavras: ");
            scanf("%s", nomeArquivoPalavras);
            criarArquivoPalavras(nomeArquivoPalavras, listaPalavras, tamanhoLista);
            break;
        }
        case 7: {
            inverterOrdemPalavras(listaPalavras, tamanhoLista);
            printf("Ordem das palavras invertida.\n");
            break;
        }
        case 0:
          printf("\nSaindo do programa. Até mais!\n");
          break;
      
        default:
            printf("Opcao invalida.\n");
    }
    //Enquanto a opção não for 0 vai continuar rodando
    }while(opcao!=0);
  
  //Desaloca o bloco de memória
    free(listaPalavras);

    return 0;
}
