/*
 * Opgave 11 s.471 - Merging of two arrays
 *
 * Programmer: Thomas Bjeldbak Madsen    Date completed: 14/10/2021
 * Instructor: Kurt Nørmark              Class: IMPR (DAT1, SW1, IxD3) - AAL E21
 *
 * This program merges two arrays and sorts them.
 */

#include <stdio.h>

#define A 5
#define B 3

void merged_sorted_array(double first_array[], double second_array[]);

int main()
{

    double first_array [] = {-10.5, -1.8, 3.5, 6.3, 7.2};
    double second_array [] = {-1.8, 3.1, 6.3};

    merged_sorted_array(first_array, second_array);

    return (0);
} 

void merged_sorted_array(double first_array[], double second_array[])
{

    int i = 0, j = 0, k = 0;
    double third_array[A + B];

    while(i <= A && j <= B ){
        if(first_array[i] < second_array[j]){
            third_array[k] = first_array[i];
            i++;
            k++;
        }

        else if(first_array[i] == second_array[j]){
            third_array[k] = first_array[i];
            i++;
            j++;
            k++;
        }   

        else{
            third_array[k] = second_array[j];
            j++;
            k++;
        }
    }

    printf("\n After merging: \n");
    for (i = 0; i < 6; i++)
    {
        printf("%0.1lf\n", third_array[i]);
    }
}
