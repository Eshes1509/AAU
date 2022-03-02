#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double random_number(ptr);

int main(){
    
    double *ptr, random;
    int i;

    ptr = (double*) malloc(sizeof(double) * 100);

    srand(ptr);

    if (ptr == NULL){
        /* alvorlige problemer */

        printf("Malloc kan ikke allokerer pladsen, prøv igen.");

        return 0;
    }

    /* use allocated memory; */

    random = random_number(ptr);

    for (i = 1; i <= 100; ++i){
        printf("This is a random number in the array(ptr): %f", random)
    }

    free(ptr);

    return 0;
}

double random_number(*ptr){
return (rand(ptr) = ptr + 1);
}
