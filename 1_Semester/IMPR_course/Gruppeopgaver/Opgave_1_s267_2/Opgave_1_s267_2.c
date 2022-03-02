#include <stdio.h>

int sum_iter(int stop);
int sum_formula(int n);

int main(void)
{
    int n, stop, sum, res_sum_iter, res_sum_formula;

    printf("Enter the value of n: ");
    scanf("%d", &stop);

    res_sum_iter = sum_iter(stop);
    res_sum_formula = sum_formula(stop);

    printf("%d\n", res_sum_iter);
    printf("%d\n", res_sum_formula);

    res_sum_iter == res_sum_formula ? printf("\nThey are the same\n") : printf("\nThey are not the same\n");

    return (0);
}

int sum_iter(int stop) {

    #define BEGIN 1
    #define STEP 1
    int sum = 0, n;

    for (n = BEGIN;
         n <= stop;
         n += STEP)
    {
        sum += n;
    }


return sum;
}

int sum_formula(int stop) {

    int sammenligning, n;

    ((stop * (stop + 1)) / 2);

return sammenligning;
}
