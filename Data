#include <stdio.h>
#include <time.h>
int main(){
  time_t tempo = time(NULL);
  struct tm tm= *localtime(&tempo);
  int dia_da_semana = tm.tm_wday;
  printf("Data: %d-%d-%d \n" ,tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
  printf("Hora: %d:%d:%d\n",tm.tm_hour-3, tm.tm_min,tm.tm_sec);
  printf("Dia da Semana: ");
  if (dia_da_semana==0){
    printf("Domingo");
  }
  else if (dia_da_semana==1){
    printf("Segunda");
  }
  else if (dia_da_semana==2){
    printf("Terça");
  }
  else if (dia_da_semana==3){
    printf("Quarta");
  }
  else if (dia_da_semana==4){
    printf("Quinta");
  }
  else if (dia_da_semana==5){
    printf("Sexta");
  }
  else if (dia_da_semana==6){
    printf("Sabado");
  }
    
  return 0;
}
