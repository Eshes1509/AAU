#include <stdio.h>
#define CBEGIN 1
#define CLIMIT 30000
#define CSTEP 1

int main(void)
{
    double start = 9870, years = 0, count_years, population = 9870;

    printf("    Year     Population\n");

    for (years = CBEGIN;
         population <= CLIMIT;
         years += CSTEP)
    {
        population = 1.1 * population;
        printf("%4c%3.0f%5c%7.0f\n", '    ', years, '   ', population);
    }

    years -= 1;
    printf("It will take %.0f years to get a population of %.0f.\n", years, population);
    return (0);
}
