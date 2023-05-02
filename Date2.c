//Implemente uma função que receba uma struct representando uma data e retorne o dia da semana correspondente (1 -segunda-feira, 2 -terça-feira, etc.).

//biblioteca de entrada e saída de dados
#include <stdio.h>

//armazenando dados da data em uma struct
struct sg_data {
    int sg_dia; //variavel para colocar o dia
    int sg_mes; //variavel para colocar o mês
    int sg_ano; //variavel para colocar o ano
};

//função para armazenar os dados da struct e representar o dia da semana
int sg_diaDaSemana(struct sg_data s) {
    int sg_q = s.sg_dia; //variavel inteira para obter o dia
    int sg_m = s.sg_mes; //variavel inteira para obter o mês
    int sg_K = s.sg_ano % 100; //variavel inteira para obter o ano
    int sg_J = s.sg_ano / 100; //variavel inteira para obter o ano
    int sg_h; //variável de ajuste

  // condição para o mês
    if (sg_m <= 2) {
        sg_m += 12; //a variavel mês vai somando 12
        sg_K--; //a variavel de ano diminui 1
    }

    sg_h = (sg_q + ((13*(sg_m+1))/5) + sg_K + (sg_K/4) + (sg_J/4) - 2*sg_J) % 7; //variavel de ajuste com calculo para o dia, mes e ano

    //ajuste para obter o dia da semana correto
    if (sg_h == 0) {
        sg_h = 7; // o ajuste recebe 7 quando o indice é igual a 0
    }

    return sg_h; //retorna o valor do ajuste
}

//código principal para entrada e saída de dados
int main() {
    struct sg_data s; //nomeando a struct

    //exemplo de uso da função
    s.sg_dia = 18; // inserindo o dia
    s.sg_mes = 4; //inserindo o mês
    s.sg_ano = 2023; // inserindo o ano
  

    int sg_diaSemana = sg_diaDaSemana(s); //variavel pra armazenar a função dia da semana
    //caso o indice do dia da semana for 2 mostra segunda-feira
    if(sg_diaSemana==2){
      printf("Dia da semana: Segunda_Feira \n");
    //caso o indice do dia da semana for 3 mostra terça-feira
    }else if(sg_diaSemana==3){
      printf("Dia da semana: Terça-Feira \n");
    //caso o indice do dia da semana for 4 mostra quarta-feira
    }else if(sg_diaSemana==4){
      printf("Dia da semana: Quarta-Feira \n");
    //caso o indice do dia da semana for 5 mostra quinta-feira
    }else if(sg_diaSemana==5){
      printf("Dia da semana: Quinta-Feira \n");
    //caso o indice do dia da semana for 6 mostra sexta-feira
    }else if(sg_diaSemana==6){
      printf("Dia da semana: Sexta-Feira \n");
    //caso o indice do dia da semana for 7 mostra sábado
    }else if(sg_diaSemana==7){
      printf("Dia da semana: Sábado \n");
    //caso o indice do dia da semana for 1 mostra domingo
    }else{
      printf("Dia da semana: Domingo \n");
    }
    return 0; //encerra a função main
}
