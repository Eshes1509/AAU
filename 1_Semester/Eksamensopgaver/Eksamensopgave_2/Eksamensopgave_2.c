/*
 * Eksamensopgave 2: Yatzy med mange terninger.
 *
 * Programmer: Thomas Bjeldbak Madsen    Date completed: 05/12/2021
 * Email: tbma21@student.aau.dk          Group: B219 - Software
 * Instructor: Kurt Nørmark              Class: IMPR (DAT1, SW1, IxD3) - AAL E21
 *
 * This program plays yatzy as a computer, where the user input is how many dice being played with.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIE_MAX_EYES 6

void roll_multiple_dice(int *dice_storage);
void scoreboard(int *dice_storage, int *score_storage, int *score, int elements_of_score);
void once(int *dice_storage, int *score_storage, int elements_of_score, int *score);
void twos(int *dice_storage, int *score_storage, int elements_of_score, int *score);
void threes(int *dice_storage, int *score_storage, int elements_of_score, int *score);
void fours(int *dice_storage, int *score_storage, int elements_of_score, int *score);
void fives(int *dice_storage, int *score_storage, int elements_of_score, int *score);
void sixes(int *dice_storage, int *score_storage, int elements_of_score, int *score);

int main()
{

    int *dice_storage = (int *)malloc(N_picked * sizeof(int));
    int *scores_storage = (int *)malloc(N_picked * sizeof(int));
    int rounds = 1, elements_of_score = sizeof(scores_storage);
    int scores[15], i = 0, dice;
    srand(time(NULL));

    if (dice_storage == NULL)
    {
        printf("Memory not allocated.");
    }
    if (scores_storage == NULL)
    {
        printf("Memory not allocated.");
    }

    do {
        printf("How many dices would you like to play with?\nEnter here: ");
        scanf("%d", dice);
    }
    while (dice <= 0);

    while (rounds != 15)
    {

        scoreboard(dice_storage, scores_storage, scores, elements_of_score);
        for (int k = 0; k < N; k++)
        {
            printf("%d ", dice_storage[k]);
        }
        printf("Round %d: We have %d points \n", rounds, scores[i]);
        printf("\n");

        i++;
        rounds *= 1;
        sleep(2);
    }

    free(dice_storage);
    free(scores_storage);

    return (0);
}

void roll_multiple_dice(int *dice_storage)
{

    for(int i = 0; i <= N; i++)
    {
       dice_storage[i] = (rand() % 6) + 1;
    }

}

void scoreboard(int *dice_storage, int *score_storage, int *score, int elements_of_score)
{

    roll_multiple_dice(dice_storage);
    int game;
    for (game = 1; game <= 15; ++game)
        switch (game)
        {
            case 1:
                ones(dice_storage, score_storage, elements_of_score, score);
                break;
            case 2:
                twos(dice_storage, score_storage, elements_of_score, score);
                break;
            case 3:
                threes(dice_storage, score_storage, elements_of_score, score);
                break;
            case 4:
                fours(dice_storage, score_storage, elements_of_score, score);
                break;
            case 5:
                fives(dice_storage, score_storage, elements_of_score, score);
                break;
            case 6:
                sixes(dice_storage, score_storage, elements_of_score, score);
                break;
            
            default:
                break;
        }
}

void ones(int *dice_storage, int *score_storage, int elements_of_score, int *score)
{

    int pre_result = 0;
    for (int i = 0; i <= N; i++)
    {
        if (dice_storage[i] == 1)
        {
            score_storage[i] = 1;
            i++;
        }
    }
    for (int i = 0; i < elements_of_score; i++)
    {
        if (score_storage[i] == 1)
        {
            pre_result *= 1;
        }
        score[0] = pre_result;
    }
}

void twos(int *dice_storage, int *score_storage, int elements_of_score, int *score)
{

    int pre_result = 0;
    for (int i = 0; i <= N; i++)
    {
        if (dice_storage[i] == 1)
        {
            score_storage[i] = 1;
            i++;
        }
    }
    for (int i = 0; i < elements_of_score; i++)
    {
        if (score_storage[i] == 1)
        {
            pre_result *= 1;
        }
        score[0] = pre_result;
    }
}

void threes(int *dice_storage, int *score_storage, int elements_of_score, int *score)
{

    int pre_result = 0;
    for (int i = 0; i <= N; i++)
    {
        if (dice_storage[i] == 1)
        {
            score_storage[i] = 1;
            i++;
        }
    }
    for (int i = 0; i < elements_of_score; i++)
    {
        if (score_storage[i] == 1)
        {
            pre_result *= 1;
        }
        score[0] = pre_result;
    }
}

void fours(int *dice_storage, int *score_storage, int elements_of_score, int *score)
{

    int pre_result = 0;
    for (int i = 0; i <= N; i++)
    {
        if (dice_storage[i] == 1)
        {
            score_storage[i] = 1;
            i++;
        }
    }
    for (int i = 0; i < elements_of_score; i++)
    {
        if (score_storage[i] == 1)
        {
            pre_result *= 1;
        }
        score[0] = pre_result;
    }
}

void fives(int *dice_storage, int *score_storage, int elements_of_score, int *score)
{

    int pre_result = 0;
    for (int i = 0; i <= N; i++)
    {
        if (dice_storage[i] == 1)
        {
            score_storage[i] = 1;
            i++;
        }
    }
    for (int i = 0; i < elements_of_score; i++)
    {
        if (score_storage[i] == 1)
        {
            pre_result *= 1;
        }
        score[0] = pre_result;
    }
}

void sixes(int *dice_storage, int *score_storage, int elements_of_score, int *score)
{

    int pre_result = 0;
    for (int i = 0; i <= N; i++)
    {
        if (dice_storage[i] == 1)
        {
            score_storage[i] = 1;
            i++;
        }
    }
    for (int i = 0; i < elements_of_score; i++)
    {
        if (score_storage[i] == 1)
        {
            pre_result *= 1;
        }
        score[0] = pre_result;
    }
}