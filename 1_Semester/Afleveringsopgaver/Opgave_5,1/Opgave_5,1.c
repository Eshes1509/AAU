/*
 * Opgave 5.1 - Trinvis forfinelse af solveQuadraticEquation
 *
 * Programmer: Thomas Bjeldbak Madsen    Date completed: 14/10/2021
 * Instructor: Kurt Nørmark              Class: IMPR (DAT1, SW1, IxD3) - AAL E21
 *
 * This program solves a quadratic equation.
 */

#include <stdio.h>
#include <math.h>

void solveQuadraticEquation(double a, double b, double c);
double find_discriminant(double a, double b, double c);
double find_root1(double b, double discriminant, double a);
double find_root2(double b, double discirminant, double a);

int main(void)
{

  double a = 1.0, b = -8.0, c = 15.0,
         d = 2.0, e = 8.0, f = 2.0,
         g, h, i;

  /* First call - coefficents are values of variables */
  solveQuadraticEquation(a, b, c);

  /* Second call - coefficents are values of expressions */
  solveQuadraticEquation(d - 1, -e, 7 * f + 1);

  /* Third call - coefficents are entered by user outside solveQuadraticEquation */
  do
  {
    printf("Enter coeficients a, b, and c: ");
    scanf("%lf %lf %lf", &g, &h, &i);
    if (g != 0 && h != 0 && i != 0)
    {
      solveQuadraticEquation(g, h, i);
    }
    else
    {
      printf("Please enter a coeficient that is not 0.\n\n");
    }
  } while (g != 0 || h != 0 || i != 0);

  return 0;
}

void solveQuadraticEquation(double a, double b, double c)
{
  double ref_discriminant, root1, ref_root_1, ref_root_2;

  ref_discriminant = find_discriminant(a, b, c);

  if (ref_discriminant < 0)
    printf("No roots\n");
  else if (ref_discriminant == 0)
  {
    root1 = -b / (2 * a);
    printf("One root: %f\n", root1);
  }
  else
  {
    ref_root_1 = find_root1(b, ref_discriminant, a);
    ref_root_2 = find_root2(b, ref_discriminant, a);
    printf("Two roots: %0.3f and %0.3f\n", ref_root_1, ref_root_2);
  }
}

double find_discriminant(double a, double b, double c)
{
  double discriminant;

  discriminant = b * b - 4 * a * c;

  return discriminant;
}

double find_root1(double b, double discriminant, double a)
{
  double root1;

  root1 = (-b + sqrt(discriminant)) / (2 * a);

  return root1;
}

double find_root2(double b, double discriminant, double a)
{
  double root2;

  root2 = (-b - sqrt(discriminant)) / (2 * a);

  return root2;
}
