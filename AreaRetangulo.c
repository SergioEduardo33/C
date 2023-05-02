#include <stdio.h>
struct retangulo{
  float altura;
  float largura;
  float area;
};
int main(void) {
  struct retangulo p;
  printf("Informe a altura: \n");
  scanf("%f",&p.altura);
  printf("Informe a largura: \n");
  scanf("%f",&p.largura);
  p.area= (p.altura * p. largura);
  printf("A área desse retângulo é : %.1f",p.area);
  return 0;
}
