#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUMBER_OF_PROGRAMS 3

int draw_random_exam_program_number(void);
void print_exam_program_message(int program_number);

int main(void) {
  int program_number;

  srand(time(NULL)); 
  system("cls");

  program_number = draw_random_exam_program_number();
  print_exam_program_message(program_number);

  sleep(30);
  system("cls");
  
  return EXIT_SUCCESS;
}

int draw_random_exam_program_number(void){
  int r = rand() % NUMBER_OF_PROGRAMS;
  return r + 1;
}

void print_exam_program_message(int program_number){
  switch(program_number){
    case 1: printf("Opgave 1:  En regnemaskine paa kommandolinjen\n"); break;
    case 2: printf("Opgave 2:  Yatzy med mange terninger.\n"); break;
    case 3: printf("Opgave 3:  Fodboldturnering\n"); break;
    default: printf("Should not happen"); 
  }
}
