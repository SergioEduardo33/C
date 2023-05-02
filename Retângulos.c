//Crie uma struct chamada "Retangulo" que contenha dois campos: base e altura (ambos do tipo float). Implemente uma função que receba um retângulo e calcule sua área. Além disso, implemente uma função que receba dois retângulos e retorne 1 seo primeiro retângulo tiver uma área maior que o segundo, -1 se o segundo retângulo tiver uma área maior que o primeiro e 0 se as áreas forem iguais.

// biblioteca padrão de entrada e saída de dados em C
#include <stdio.h>

// Definição da struct sg_retangulo
struct sg_retangulo {
    float base;  //variavel da base
    float altura; //variavel da altura
};

// função para calcular a área de um retângulo
float calcularArea(struct sg_retangulo s) {
    return s.base * s.altura; //retornando a multiplicação da base pela a altura, assim tendo o resultado da área
}

// função para comparar as duas áreas dos retângulos
int compararAreas(struct sg_retangulo s1, struct sg_retangulo s2) {
    float area1 = calcularArea(s1); // float para calcular a área do retangulo 1 
    float area2 = calcularArea(s2); // float para calcular a área do retangulo 2 

  // retorna 1 caso a área 1 > área 2
    if (area1 > area2) {
        return 1;
  // retorna -1 caso a área 2 > a área 1 
    } else if (area1 < area2) {
        return -1;
  // retorna 0 caso a área 1 seja igual a área 2 
    } else {
        return 0;
    }
}
// função principal que roda o programa
int main() {
    struct sg_retangulo sg_retangulo1 ={8.0, 5.0}; //para inserir o valor da base e da altura no retângulo 1 
    struct sg_retangulo sg_retangulo2 = {4.0, 6.0}; //para inserir o valor da base e da altura no retângulo 2
    
    float area1 = calcularArea(sg_retangulo1); // chamando a função "calcularArea" para calcular a área no retângulo 1 
    float area2 = calcularArea(sg_retangulo2); // chamando a função "calcularArea" para calcular a área no retângulo 2
    
    printf("Área do retângulo 1: %.2f\n", area1); //mostrar na tela a área 1 
    printf("Área do retângulo 2: %.2f\n", area2); //mostrar na tela a área 2 
    
    int sg_comparacao = compararAreas(sg_retangulo1, sg_retangulo2); // variavel que compara as áreas do retângulo 
    // caso sg_comparação seja igual a 1 é porque está retornando 1, ou seja, a como é visto la em cima, no caso a área 1 > área 2 
    if (sg_comparacao == 1) { 
        printf("O retângulo 1 tem uma área maior que o retângulo 2\n");
    // caso sg_comparação seja igual a -1 é porque está retornando -1, ou seja, a como é visto la em cima, no caso a área 2 > área 1 
    } else if (sg_comparacao == -1) {
        printf("O retângulo 2 tem uma área maior que o retângulo 1\n");
    // caso sg_comparação seja igual a 0 é porque está retornando 0, ou seja, a como é visto la em cima, no caso a área 1 é igual a  área 2 
    } else {
        printf("Os retângulos têm áreas iguais\n");
    }
    return 0; //encerra a função main
}
