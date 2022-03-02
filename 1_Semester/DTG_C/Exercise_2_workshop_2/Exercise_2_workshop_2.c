#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Change this to 500, 1000, 2000, 4000, or 9000 for the different lists*/
#define N 9000

int LinSearch(int array[], int x);
int BinSearch(int array[], int x);

int main(void){
  int x;
  char filename[20];
  FILE *myFile;
  int array[N];
  int k;
  /*change this for more or less runs of the algorithm*/
  int runs = pow(10,6);
  int i;

  sprintf(filename, "List%d.txt", N);
  printf("What number are we searching for?\n"); /* Feel free to alter this*/
  scanf("%d", &x);

  myFile = fopen(filename, "r");

  /* iList is read into array */
  for (k = 0; k < N; k++){
    fscanf(myFile, "%d", &array[k]);
  }
  fclose(myFile);

  printf("The size of the list is %d\n", N);

  /* start time */
  double startTime = clock();


  for (i = 0; i < runs; i++){
    BinSearch(array, x);
  }

  /* stop time and print */
  double endTime = clock();
  double duration = (endTime - startTime) / CLOCKS_PER_SEC;
  printf("BinSearch needed: %.7fs\n", duration);



  /* start time */
  startTime = clock();

  for (i = 0; i < runs; i++){
    LinSearch(array, x);
  }

  /* stop time and print */
  endTime = clock();
  duration = (endTime - startTime) / CLOCKS_PER_SEC;
  printf("LinSearch needed: %.7fs\n", duration);

  /* Prints the result */
  int result=LinSearch(array, x);
  if (result == 0){
     printf("%d is not in the list \n",x);
  }
  else {
      printf("%d is in position %d\n",array[result],result+1);
    }

  result=BinSearch(array, x);
  if (result == 0){
     printf("%d is not in the list \n",x);
  }
  else {
      printf("%d is in position %d\n",array[result],result+1);
    }
  printf("Done!\n"); /* Feel free to be more creative here */
  return 0;
}

int LinSearch(int array[], int x){
  int i=0, n = N;

  while (i <= n && x != array[i])
  {
    ++i;
  }
    if (i <= x)
    {
      return i;
    }
  else
  {
   return (0);
  }
}

int BinSearch(int array[], int x){
  int i = 0, j = N, m;

  while (i < j)
  {
    m = floor((i + j) / 2);

      if (x > array[m])
      {
        i = m + 1;
      }
      else
      {
        j = m;
      }
  }
  if (x == array[i])
  {
    return i;
  }
  else
  {
    return 0;
  }
}
