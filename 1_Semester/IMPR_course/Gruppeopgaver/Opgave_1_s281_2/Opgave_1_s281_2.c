#include <stdio.h>

int population_projection(double start, double population, double years);

int main(void)
{
    double start = 9870, years = 0, count_years, population = 9870;
    int res_years;

    printf("    Year     Population\n");

    res_years = population_projection(start, years, population);

    printf("It will take %.0d years to get a population of %.0f.\n", res_years, population);
    return (0);
}

int population_projection(double start, double population, double years) {

    #define CBEGIN 1
    #define CLIMIT 30000
    #define CSTEP 1

    int amount_of_years, amount_of_population;

    for (years = 1;
         population <= CLIMIT;
         years ++);
    {
        population = (start * pow(1.10) , (double) years);
        printf("%4c%3.0f%5c%7.0f\n", '    ', years, '   ', population);
    }

    return amount_of_years;
}