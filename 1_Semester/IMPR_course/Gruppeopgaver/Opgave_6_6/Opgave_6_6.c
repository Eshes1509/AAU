#include <stdio.h>
#include <stdlib.h>

#define euro 0.89
#define krone 6.66
#define ruble 66.43
#define yen 119.9

void valutaomregner(double dollar, double *euros, double *kroner, double *rubler, double *yener);

int main(){

    double dollar = 0.0, euros, kroner, rubler, yener;

    printf("\nInput how many dollars you want to convert to; euro, kroner, rubler and yen: ");
    scanf("%lf", &dollar);

    valutaomregner(dollar, &euros, &kroner, &rubler, &yener);

    printf("%0.2f euro\n", euros);
    printf("%0.2f kroner\n", kroner);
    printf("%0.2f rubler\n", rubler);
    printf("%0.2f yen\n", yener);

    return(0);
}

void valutaomregner(double dollar, double *euros, double *kroner, double *rubler, double *yener){

    *euros = dollar * euro;
    *kroner = dollar * krone;
    *rubler = dollar * ruble;
    *yener = dollar * yen;
}



/* Skriv et C program som konverterer valuta i dollars til euro, kroner, rubler og yen. I kan antage en én dollar er 0.89 euros, 6.66 kroner, 66.43 rubler og 119.9 yen.

I denne opgave skal der indgå en funktion med én input parameter (dollar-beløbet), og fire output parametre (svarende til de fire andre valutaer).

Brug funktionen til at udskrive en omregningstabel til omregning af 1, 2, 3, ... 100 dollars til de fire andre valutaer.

(Denne opgave svarer til programmeringsprojekt 1, side 384 i 7. udgave af lærebogen).*/
