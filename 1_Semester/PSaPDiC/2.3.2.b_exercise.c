#include <stdio.h>

int main(void)
{
    double side, area;

    printf("Enter the sidelengths of the square: \n");
    scanf("%lf", &side);

    area = side * side;

    printf("The area of a square whose side length is %f cm is %f square cm.\n", side, area);

    return(0);
}