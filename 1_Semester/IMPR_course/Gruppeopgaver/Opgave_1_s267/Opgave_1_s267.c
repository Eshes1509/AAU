#include <stdio.h>
#define BEGIN 1
#define STEP 1

int main(void)
{
    int n, stop, sum = 0;

    printf("Enter the value of n: ");
    scanf("%d", &stop);

    for (n = BEGIN;
         n <= stop;
         n += STEP)
    {
        sum += n;
    }

    printf("%d\n", sum);
    printf("%d\n", ((stop * (stop + 1)) / 2));

    sum == ((stop * (stop + 1)) / 2) ? printf("\nThey are the same\n") : printf("\nThey are not the same\n");

    return (0);
}
