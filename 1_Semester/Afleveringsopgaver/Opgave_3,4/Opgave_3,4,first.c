/* Side 200 */

/* 
* Opgave 3.4 - Timer, minutter og sekunder - igen
*
* Programmer: Thomas Bjeldbak Madsen    Date completed: 13/09/2021
* Instructor: Kurt Nørmark              Class: IMPR (DAT1, SW1, IxD3) - AAL E21
*
* This program receives an input of seconds, and afterwards outputs in hours,
* minutes and seconds. 
*/

#include <stdio.h>
#define SECONDS_HOURS 3600
#define SECONDS_MINUTES 60

int main(void)
{
    int minutes, hours, input_seconds;

    printf("\nInput how many seconds to convert: ");
    scanf("%d", &input_seconds);

    hours = input_seconds / SECONDS_HOURS;
    input_seconds = input_seconds % SECONDS_HOURS;

    minutes = input_seconds / SECONDS_MINUTES;
    input_seconds = input_seconds % SECONDS_MINUTES;

    if (hours >= 2)
        printf("%d hours, ", hours);
    else if (hours == 1)
        printf("%d hour, ", hours);

    if (minutes >= 2)
        printf("%d minutes, ", minutes);
    else if (minutes == 1)
        printf("%d minute, ", minutes);

    if (input_seconds >= 2)
        printf("%d seconds.\n", input_seconds);
    else if (input_seconds == 1)
        printf("%d second.\n", input_seconds);
        
    return(0);
}
