#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100

struct Livro {
    int codigo;
    char titulo[100];
    char autor[100];
    int quantidade;
};

struct Livro inventario[MAX_LIVROS];
int totalLivros = 0;

//Função que adiciona um novo livro ao inventário
void adicionarLivro(int codigo, const char *titulo, const char *autor, int quantidade) {
    if (totalLivros < MAX_LIVROS) {
        struct Livro *novoLivro = &inventario[totalLivros];
        novoLivro->codigo = codigo;
        strcpy(novoLivro->titulo, titulo);
        strcpy(novoLivro->autor, autor);
        novoLivro->quantidade = quantidade;

        totalLivros++;

        printf("Livro adicionado ao inventário com sucesso!\n");
    } else {
        printf("O inventário está cheio. Não é possível adicionar mais livros.\n");
    }
}

// Função que remove um livro do inventário
void removerLivro(int codigo) {
    int i;
    for (i = 0; i < totalLivros; i++) {
        if (inventario[i].codigo == codigo) {
            int j;
            for (j = i; j < totalLivros - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            totalLivros--;
            printf("Livro removido do inventário com sucesso!\n");
            return;
        }
    }
    printf("Livro com o código %d não encontrado no inventário.\n", codigo);
}

// Função que imprime todos os livros no inventário
void imprimirLivros() {
    int i;
    for (i = 0; i < totalLivros; i++) {
        struct Livro *livro = &inventario[i];
        printf("Código: %d\n", livro->codigo);
        printf("Título: %s\n", livro->titulo);
        printf("Autor: %s\n", livro->autor);
        printf("Quantidade: %d\n\n", livro->quantidade);
    }
}

// Função que atualiza a quantidade de livros para um livro existente
void atualizarQuantidadeLivro(int codigo, int quantidade) {
    int i;
    for (i = 0; i < totalLivros; i++) {
        if (inventario[i].codigo == codigo) {
            inventario[i].quantidade += quantidade;
            printf("Quantidade atualizada com sucesso!\n");
            return;
        }
    }
    printf("Livro com o código %d não encontrado no inventário.\n", codigo);
}

// Função que altera os dados de um livro a partir do código
void alterarDadosLivro(int codigo, const char *titulo, const char *autor) {
    int i;
    for (i = 0; i < totalLivros; i++) {
        if (inventario[i].codigo == codigo) {
            struct Livro *livro = &inventario[i];
            strcpy(livro->titulo, titulo);
            strcpy(livro->autor, autor);
            printf("Dados do livro atualizados com sucesso!\n");
            return;
        }
    }
    printf("Livro com o código %d não encontrado no inventário.\n", codigo);
}
// Função para a realização de testes 
void realizarTeste() {
    printf("Realizando teste do programa...\n\n");

    // Adicionar livros
    printf("Adicionando livros...\n");
    adicionarLivro(1, "O Senhor dos Anéis: A Sociedade do Anel", "J.R.R. Tolkien", 10);
    adicionarLivro(2, "Harry Potter e a Pedra Filosofal", "J.K. Rowling", 5);
    adicionarLivro(3, "Em defesa de Cristo", "Lee Strobel", 8);
    printf("\n");

    // Imprimir lista de livros
    printf("Lista de livros:\n");
    imprimirLivros();
    printf("\n");

    // Remover um livro
    printf("Removendo livro com código 2...\n");
    removerLivro(2);
    printf("\n");

    // Atualizar quantidade de livros
    printf("Atualizando quantidade de livros (código 1, quantidade -2)...\n");
    atualizarQuantidadeLivro(1, -2);
    printf("\n");

    // Imprimir lista de livros novamente
    printf("Lista de livros após as alterações:\n");
    imprimirLivros();
    printf("\n");
}
//Função principal do código 
int main() {
    int opcao;
    int codigo, quantidade;
    char titulo[100], autor[100];
    realizarTeste();
//Criação do menu
    do {
        printf("\n=-=-=-=- Menu Interativo =-=-=-=-");
        printf("\n1. Adicionar um livro");
        printf("\n2. Remover um livro");
        printf("\n3. Imprimir todos os livros");
        printf("\n4. Atualizar a quantidade de livros");
        printf("\n5. Alterar os dados de um livro");
        printf("\n0. Sair");
        printf("\n\nEscolha uma opção: ");
        scanf("%d", &opcao);
// O que fazer com cada opção escolhida
        switch (opcao) {
            case 1:
                printf("\nDigite o código do livro: ");
                scanf("%d", &codigo);
                printf("Digite o título do livro: ");
                getchar();
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0'; // Remover o caractere de nova linha
                printf("Digite o autor do livro: ");
                fgets(autor, sizeof(autor), stdin);
                autor[strcspn(autor, "\n")] = '\0'; // Remover o caractere de nova linha
                printf("Digite a quantidade de livros: ");
                scanf("%d", &quantidade);
                adicionarLivro(codigo, titulo, autor, quantidade);
                break;

            case 2:
                printf("\nDigite o código do livro a ser removido: ");
                scanf("%d", &codigo);
                removerLivro(codigo);
                break;

            case 3:
                printf("\nListando todos os livros:\n");
                imprimirLivros();
                break;

            case 4:
                printf("\nDigite o código do livro a ser atualizado: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade a ser adicionada/removida(+/-): ");
                scanf("%d", &quantidade);
                atualizarQuantidadeLivro(codigo, quantidade);
                break;

            case 5:
                printf("\nDigite o código do livro a ser alterado: ");
                scanf("%d", &codigo);
                printf("Digite o novo título do livro: ");
                getchar();
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0'; // Remover o caractere de nova linha
                printf("Digite o novo autor do livro: ");
                fgets(autor, sizeof(autor), stdin);
                autor[strcspn(autor, "\n")] = '\0'; // Remover o caractere de nova linha
                alterarDadosLivro(codigo, titulo, autor);
                break;

            case 0:
                printf("\nSaindo do programa. Até mais!\n");
                break;

            default:
                printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    //quando a opção for igual a 0, o programa encerra
    } while (opcao != 0);

    return 0;
}
