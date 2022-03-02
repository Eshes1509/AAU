#include <stdio.h>
#define CBEGIN 100
#define CLIMIT 0
#define CSTEP 10

int main(void)
{
    double inch, centimeter;

    printf("    Centimeter     Inches\n");

    for(centimeter = CBEGIN;
        centimeter >= CLIMIT;
        centimeter -= CSTEP)
        {
            inch = 0.3937 * centimeter;
            printf("%5c%.2f%8c%.2f\n", '    ', centimeter, '   ', inch);
        }
return(0);
}
