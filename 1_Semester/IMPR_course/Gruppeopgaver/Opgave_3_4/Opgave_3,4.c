/* 
* Opgave 3.4 - Timer, minutter og sekunder - igen
*
* Programmer: Thomas Bjeldbak Madsen    Date completed: 19/09/2021
* Instructor: Kurt Nørmark              Class: IMPR (DAT1, SW1, IxD3) - AAL E21
*
* This program receives an input of seconds, and afterwards outputs in hours,
* minutes and seconds. 
*/

#include <stdio.h>
/* SECONDS_MINUTES = 60 seconds. */
#define SECONDS_MINUTES 60
/* SECONDS_HOURS = 60 * SECONDS_MINUTES. */
#define SECONDS_HOURS (60 * SECONDS_MINUTES)

int main(void)
{
    int minutes, hours, seconds;

    printf("\nInput how many seconds to convert: ");
    scanf("%d", &seconds);

    /* Calculating the amount of seconds to hours and minutes. */
    hours = seconds / SECONDS_HOURS;
    seconds = seconds % SECONDS_HOURS;

    minutes = seconds / SECONDS_MINUTES;
    seconds = seconds % SECONDS_MINUTES;

    /* Hours. */
    /* The amount of hours is going through if statements, which determines how it should be output. If nothing is true, then nothing will be output. */
    if ((hours >= 1 && minutes >= 1 && seconds == 0) || (hours >= 1 && minutes == 0 && seconds >= 1) || (minutes == 0 && seconds == 0))
    {
        if (hours == 1 && minutes == 0 && seconds >= 1)
        {
            printf("%d hour and ", hours);
        }
        else if ((hours > 1 && minutes == 0 && seconds >= 1) || (hours >= 1 && minutes >= 1 && seconds == 0))
        {
            printf("%d hours and ", hours);
        }
        else if (hours >= 2)
        {
            printf("%d hours.\n", hours);
        }
        else
        {
            printf("%d hour.\n", hours);
        }
    }
    else if (hours >= 2 && minutes > 0 && seconds > 0)
    {
        printf("%d hours, ", hours);
    }
    else if (hours == 1)
    {
        printf("%d hour, ", hours);
    }

    /* Minutes. */
    /* The amount of minutes is going through if statements, which determines how it should be output. If nothing is true, then nothing will be output. */
    if (minutes >= 1)
    {
        if (hours >= 0 && minutes == 1 && seconds >= 1)
        {
            printf("%d minute and ", minutes);
        }
        else if (hours >= 0 && minutes > 1 && seconds >= 1)
        {
            printf("%d minutes and ", minutes);
        }
        else if (minutes >= 2 && seconds == 0)
        {
            printf("%d minutes.\n", minutes);
        }
        else if (minutes == 1 && seconds == 0)
        {
            printf("%d minute.\n", minutes);
        }
    }

    /* Seconds. */
    /* The amount of seconds is going through an if statement, which determines how it should be output. If nothing is true, then nothing will be output. */
    if (seconds >= 2)
    {
        printf("%d seconds.\n", seconds);
    }
    else if (seconds == 1)
    {
        printf("%d second.\n", seconds);
    }

    return (0);
}
