#include <stdio.h>
#include <string.h>
int main(){
  char palavra1[50];
  int c, i;
  printf("Escreva uma palavra: \n");
  fgets(palavra1,50,stdin);
  printf("Palavra de tras para a frente: \n");
  c = strlen(palavra1);
  for(i=c-1; i>=0; i--){
    printf("%c",palavra1[i]);
  }
  return 0;
}
