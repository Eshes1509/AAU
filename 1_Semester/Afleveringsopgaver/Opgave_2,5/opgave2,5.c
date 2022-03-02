/* 
* Opgave 2.5 - Uger, dage, timer, minutter og sekunder
*
* Programmer: Thomas Bjeldbak Madsen    Date completed: 07/09/2021
* Instructor: Kurt Nørmark              Class: IMPR (DAT1, SW1, IxD3) - AAL E21
*
* This program receives an input of seconds, and afterwards outputs in weeks, days, hours,
* minutes and seconds. 
*/

#include <stdio.h>
/* I start by defining how many seconds there is in one week, one day, one hour and one minute. */
#define SECONDS_WEEKS 604800
#define SECONDS_DAYS 86400
#define SECONDS_HOURS 3600
#define SECONDS_MINUTES 60

int main(void)
{
    int weeks, days, hours, minutes, seconds;

    /* 
    * I prompt the user to enter how many seconds they want convert into weeks, days, hours and minutes.
    * This input is stored in seconds. 
    */
    printf("\nInput how many seconds to convert: ");
    scanf("%d", &seconds);

    /* 
    * Once the user has made an input, I divide the defined week, day, hour, minute with the input and store
    * it in the "weeks", "days", "hours" and "minutes". This gives us the amount of weeks...
    * I use an "if" statement to retract the inputted seconds and the remaining seconds is 
    * stored under "seconds" again. In the end interger "seconds" will be the remaining of the calculated seconds.
    */
    weeks = seconds / SECONDS_WEEKS;
    if (weeks >= 1)
        seconds = seconds % SECONDS_WEEKS;

    days = seconds / SECONDS_DAYS;
    if (days >= 1)
        seconds = seconds % SECONDS_DAYS;

    hours = seconds / SECONDS_HOURS;
    if (hours >= 1)
        seconds = seconds % SECONDS_HOURS;

    minutes = seconds / SECONDS_MINUTES;
    if (minutes >= 1)
        seconds = seconds % SECONDS_MINUTES;

    /* 
    * Once every week, day, hour and minute has been calculated, I print it so it displays the assigned 
    * value with the datatype integer. 
    */
    printf("\n%d weeks, %d days, %d hours, %d minutes, %d seconds \n\n", weeks, days, hours, minutes, seconds);

    return (0);
}
