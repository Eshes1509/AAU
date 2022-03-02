/* 
* Opgave 4.6 - Ligefrem programmering af 'største fælles divisor'.
*
* Programmer: Thomas Bjeldbak Madsen    Date completed: 27/09/2021
* Instructor: Kurt Nørmark              Class: IMPR (DAT1, SW1, IxD3) - AAL E21
*
* This program finds the GCD of two positive integers, and takes in account of errors that could occur.
*/

#include <stdio.h>

int main(void)
{

    int a, b, small, large, remainder, status, error;
    char skip;

    /* This uses a flag-controlled loop to cut out any errors there could be.  */
    do
    {
        error = 0;

        printf("Please enter 2 positive integers: ");
        status = scanf("%d%d", &a, &b);

        if (status != 2)
        {
            error = 1;
            scanf("%c", &skip);

            printf("\nInvalid character: %c. ", skip);
            printf("Skipping rest of line.\n\n");
        }
        else if (a < 0 && b > 0)
        {
            error = 1;
            printf("\nNumber %d is not a positive integer.\n\n", a);
        }
        else if (a > 0 && b < 0)
        {
            error = 1;
            printf("\nNumber %d is not a positive integer.\n\n", b);
        }
        else if (a < 0 && b < 0)
        {
            error = 1;
            printf("\nNumber %d and %d is not a positive integer.\n\n", a, b);
        }

        do
        {
            scanf("%c", &skip);
        } while (skip != '\n');

    } while (error);

    /* This assigns the variable small and large to the smallest and largest number. */
    small = a <= b ? a : b;
    large = a <= b ? b : a;

    /* This while loop finds the greatest common divisor of two positive intergers. */
    while (small > 0)
    {
        remainder = large % small;
        large = small;
        small = remainder;
    }

    printf("\nGCD of %d and %d is %d.\n\n", a, b, large);

    return (0);
}
