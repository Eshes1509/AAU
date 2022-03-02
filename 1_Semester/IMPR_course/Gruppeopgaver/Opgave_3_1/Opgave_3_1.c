#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA 0.0001

int main(void)
{
    double x,y,r;

    printf("Pleace insert x, y and r in syntax x,y,r: ");
    scanf("%lf, %lf, %lf", &x, &y, &r);

    int on, of, in;
    on = x < sqrt(r*r - y*y) + DELTA && y < sqrt(r*r - x*x) + DELTA &&
         x > sqrt(r*r - y*y) - DELTA && y > sqrt(r*r - x*x) - DELTA;
    of = x > sqrt(r*r - y*y) && y > sqrt(r*r - x*x);
    in = x < sqrt(r*r - y*y) && y < sqrt(r*r - x*x);

    printf("On:%d, Of:%d, In:%d\n", on, of, in);

    printf("%s\n",on?"on":in?"in":"of");

    return(0);
}
