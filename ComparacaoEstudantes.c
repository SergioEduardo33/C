//Crie uma struct chamada "Estudante" que contenha os campos nome (string de tamanho 50), matricula (inteiro) e notas (array de 4 floats). Implemente uma função que leia os dados de um estudante do teclado e retorne a struct preenchida. Além disso, implemente uma função que receba um estudante e calcule sua média das notas. Por fim, implemente uma função que receba dois estudantes e retorne 1 se o primeiro estudante tiver uma média maior que o segundo, -1 se o segundo estudante tiver uma média maior que o primeiro e 0 se as médias forem iguais.

//Professor esse código rodou direitinho no meu computador, mas quando testei no que tenho em casa o nome do segundo estudate é pulado então so da pra acrescentar a matrícula, mas ele da qual média é maior perfeitamente, testei várias vezes.


// biblioteca padrão de entrada e saída de dados em C
#include <stdio.h>
// biblioteca para manipulação de strings
#include <string.h>

// definição da struct sg_estudante
struct sg_estudante {
    char sg_nome[50]; //variável para o nome
    int sg_matricula;  //variável para a matícula
    float sg_notas[4]; //variável para as 4 notas
};

// função para ler os dados de um estudante do teclado
struct sg_estudante sg_lerEstudante() {
    struct sg_estudante sg_aluno; //insere os dados de um estudante no aluno
    printf("\nDigite o nome do estudante: \n"); //para o usuário colocar o nome do estudante
    fgets(sg_aluno.sg_nome, 50, stdin); //armazena o nome do estudante
    sg_aluno.sg_nome[strcspn(sg_aluno.sg_nome, "\n \r")] = '\0'; // remove o caractere de nova linha
    printf("Digite a matrícula do estudante:\n "); //para o usuário colocar a matrícula do estudante
    scanf("%d", &sg_aluno.sg_matricula); //armazena a matrícula do estudante
    printf("Digite as 4 notas do estudante: \n"); //para o usuário colocar as 4 notas do estudante
    for (int i = 0; i < 4; i++) { //for para colocar as 4 notas 
        scanf("%f", &sg_aluno.sg_notas[i]); // armazena as notas na avriavel sg_aluno
    }

    return sg_aluno; //retorna a variavel sg_aluno
}

// função para calcular a média das notas de um estudante
float sg_calcularMedia(struct sg_estudante sg_aluno) {
    float sg_soma = 0; // variavel para somar
  //varrendo as notas do aluno
    for (int i = 0; i < 4; i++) {
        sg_soma += sg_aluno.sg_notas[i]; //soma todas as notas
    }
    return sg_soma / 4; //divide a soma das notas, assim finalizando a média
}

// função para comparar as médias de dois estudantes
int sg_compararMedias(struct sg_estudante sg_aluno1, struct sg_estudante sg_aluno2) {
    float sg_media1 = sg_calcularMedia(sg_aluno1); //variavel para calcular a média do estudante 1
    float sg_media2 = sg_calcularMedia(sg_aluno2); //variavel para calcular a média do estudante 2
//caso a média 1 seja maior que a média 2 retorna 1
    if (sg_media1 > sg_media2) {
        return 1;
//caso a média 2 seja maior que a média 1 retorna -1
    } else if (sg_media1 < sg_media2) {
        return -1;
//caso a média 1 seja igual a média 2
    } else {
        return 0;
    }
}
//código principal de entrada e saída de dados
int main() {
    struct sg_estudante sg_aluno1, sg_aluno2; // struct sg_estudante recebendo aluno 1 e aluno2

    printf("\nDados do Primeiro Estudante\n"); //para o usuário colocar os dados do estudante 1 
    sg_aluno1 = sg_lerEstudante(); // variável sg_aluno 1 recebendo a funçao para ler as informações do estudante

    printf("\nDados do Segundo Estudante\n"); //para o usuário colocar os dados do estudante 2
    sg_aluno2 = sg_lerEstudante();  // variável sg_aluno 2 recebendo a funçao para ler as informações do estudante

    int sg_resultado = sg_compararMedias(sg_aluno1, sg_aluno2); //armazena a comparação das médias na variável sg_resultado
    //caso retorne 1 a média do estudante 1 é maior
    if (sg_resultado == 1) {
        printf("A média do PRIMEIRO ESTUDANTE é maior.\n");
    //caso retorne -1 a média do estudante 2 é maior
    } else if (sg_resultado == -1) {
        printf("A média do SEGUNDO ESTUDANTE é maior.\n");
    //caso retorne 0 a média dos estudantes é igual
    } else {
        printf("As médias dos estudantes são IGUAIS.\n");
    }

    return 0; //encerra a função main
}
