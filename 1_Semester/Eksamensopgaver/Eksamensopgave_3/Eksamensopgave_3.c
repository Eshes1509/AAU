/*
 * Eksamensopgave 3: Fodboldturnering.
 *
 * Programmer: Thomas Bjeldbak Madsen    Date completed: 17/12/2021
 * Email: tbma21@student.aau.dk          Group: B219 - Software
 * Instructor: Kurt Nørmark              Class: IMPR (DAT1, SW1, IxD3) - AAL E21
 *
 * This program takes in a txt file with games from the 2020-2021 Superliga season, and prints it in a scoreboard.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATCHES 132 /* Number of matches through the season */
#define TEAMS 12    /* Number of teams through the season */

enum teamNames
{
    Aab,
    ACH,
    AGF,
    BIF,
    FCK,
    FCM,
    FCN,
    LBK,
    OB,
    RFC,
    SDR,
    VB
};

struct match
{ /* Structure for the matches */
    char weekday[4];
    char date[6];
    char time[6];
    char homeTeam[4];
    char awayTeam[4];
    int homeScore;
    int awayScore;
    int spectators;
};

struct team
{ /* Structure for the teams */
    char teamName[4];
    int points;
    int goalsScored;
    int goalsScoredAgainst;
};

void readMatches(struct match match[]);
void teamSum(struct match match[], struct team team[]);
void sortTeams(struct team team[]);
void resultlist(struct team team[]);
void getTeamsReady(struct team team[]);
void teamHomeSum(struct match match[], struct team team[], int name, int i);
void teamAwaySum(struct match match[], struct team team[], int name, int i);

int main(void)
{
    struct match match[MATCHES];
    struct team team[TEAMS];

    readMatches(match);
    teamSum(match, team);
    sortTeams(team);
    resultlist(team);

    return 0;
}

void readMatches(struct match match[])
{ /* Opens the .txt file, and assigns the information to the match structure */
    FILE *ifp;
    int i, j, prevI;
    char line[60];

    ifp = fopen("kampe-2020-2021.txt", "r");

    if (ifp != NULL)
    {
        for (j = 0; j < MATCHES; j++)
        {
            i = 0;
            if (fgets(line, 60, ifp) != NULL)
            {
                while (i < 3)
                {
                    match[j].weekday[i] = line[i];
                    i++;
                }
                match[j].weekday[i] = '\0';

                i = 8;
                while (i < 13)
                {
                    match[j].date[i - 8] = line[i];
                    i++;
                }
                match[j].date[i - 8] = '\0';

                i = 14;
                while (i < 19)
                {
                    match[j].time[i - 14] = line[i];
                    i++;
                }
                match[j].time[i - 14] = '\0';

                i = 24;
                while (line[i] != ' ')
                {
                    match[j].homeTeam[i - 24] = line[i];
                    i++;
                }
                match[j].homeTeam[i - 24] = '\0';

                i += 3;
                prevI = i; /* To take care of the two letter teams */
                while (line[i] != ' ')
                {
                    match[j].awayTeam[i - prevI] = line[i];
                    i++;
                }
                match[j].awayTeam[i - prevI] = '\0';

                match[j].homeScore = line[38] - '0';
                match[j].awayScore = line[42] - '0';

                i = 48;
                while (line[i] != ' ')
                {
                    i++;
                }

                char spectatorNr[i - 48]; /* spectatorNr is made as a char[], as atoi() will crash if the array
                                             contains more characters than the number of digits the spectator number has */

                while (line[i] != ' ')
                {
                    spectatorNr[i - 48] = line[i];
                    i++;
                }
                match[j].spectators = atoi(spectatorNr);
            }
        }
        fclose(ifp);
    }
    else
    {
        printf("Something went wrong, couldn't open kampe-2020-2021.txt.");
        exit(EXIT_FAILURE);
    }
}

void teamSum(struct match match[], struct team team[])
{ /* This assigns points, goals scored and goals scored against to every team */
    int i, j;
    getTeamsReady(team);

    for (i = 0; i < MATCHES; i++)
    {
        for (j = 0; j < TEAMS; j++)
        {
            if (strcmp(match[i].homeTeam, team[j].teamName) == 0)
            {
                teamHomeSum(match, team, j, i);
            }
            else if (strcmp(match[i].awayTeam, team[j].teamName) == 0)
            {
                teamAwaySum(match, team, j, i);
            }
        }
    }
}

void sortTeams(struct team team[])
{ /* This functions sorts the teams in descending order with points as 1st priority, and goal difference 2nd */
    int i, j;
    struct team temp;

    for (i = 0; i < TEAMS; i++)
    {
        for (j = 0; j < (TEAMS - 1 - i); j++)
        {
            if (team[j].points == team[j + 1].points)
            {
                if (team[j].goalsScored - team[j].goalsScoredAgainst < team[j + 1].goalsScored - team[j + 1].goalsScoredAgainst)
                {
                    temp = team[j];
                    team[j] = team[j + 1];
                    team[j + 1] = temp;
                }
            }
            else if (team[j].points < team[j + 1].points)
            {
                temp = team[j];
                team[j] = team[j + 1];
                team[j + 1] = temp;
            }
        }
    }
}

void resultlist(struct team team[])
{ /* This prints out the final product, a sorted list of the teams */
    int i;

    printf("Team name  Points  Goals scored  Goals scored against\n");
    for (i = 0; i < TEAMS; i++)
    {
        if (strcmp(team[i].teamName, "OB") == 0 || strcmp(team[i].teamName, "VB") == 0)
        {
            printf("%s           %d          %d              %d\n", team[i].teamName, team[i].points, team[i].goalsScored, team[i].goalsScoredAgainst);
        }
        else
        {
            printf("%s          %d          %d              %d\n", team[i].teamName, team[i].points, team[i].goalsScored, team[i].goalsScoredAgainst);
        }
    }
}

void getTeamsReady(struct team team[])
{ /* This assigns the team names to their respective teams and sets all of their information to 0 */
    int i;

    strcpy(team[Aab].teamName, "AaB");
    strcpy(team[ACH].teamName, "ACH");
    strcpy(team[AGF].teamName, "AGF");
    strcpy(team[BIF].teamName, "BIF");
    strcpy(team[FCK].teamName, "FCK");
    strcpy(team[FCM].teamName, "FCM");
    strcpy(team[FCN].teamName, "FCN");
    strcpy(team[LBK].teamName, "LBK");
    strcpy(team[OB].teamName, "OB");
    strcpy(team[RFC].teamName, "RFC");
    strcpy(team[SDR].teamName, "SDR");
    strcpy(team[VB].teamName, "VB");

    for (i = Aab; i < TEAMS; i++)
    {
        team[i].points = 0;
        team[i].goalsScored = 0;
        team[i].goalsScoredAgainst = 0;
    }
}

void teamHomeSum(struct match match[], struct team team[], int name, int i)
{ /* This gives points to every home team */
    team[name].goalsScored += match[i].homeScore;
    team[name].goalsScoredAgainst += match[i].awayScore;

    if (match[i].homeScore > match[i].awayScore)
    {
        team[name].points += 3;
    }
    else if (match[i].homeScore == match[i].awayScore)
    {
        team[name].points += 1;
    }
}

void teamAwaySum(struct match match[], struct team team[], int name, int i)
{ /* This gives points to every away team */
    team[name].goalsScored += match[i].awayScore;
    team[name].goalsScoredAgainst += match[i].homeScore;

    if (match[i].homeScore < match[i].awayScore)
    {
        team[name].points += 3;
    }
    else if (match[i].homeScore == match[i].awayScore)
    {
        team[name].points += 1;
    }
}
