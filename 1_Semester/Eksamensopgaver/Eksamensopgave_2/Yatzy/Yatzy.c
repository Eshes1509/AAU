/*
 * Eksamensopgave 2: Yatzy med mange terninger.
 *
 * Programmer: Thomas Bjeldbak Madsen    Date completed: 05/12/2021
 * Email: tbma21@student.aau.dk          Group: B219 - Software
 * Instructor: Kurt Nørmark              Class: IMPR (DAT1, SW1, IxD3) - AAL E21
 *
 * Dette program spiller yatzy med en computer, hvor brugeren inputter hvor mange terninger der skal spilles med.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TERNING_MAX_OEJNE 6

void input_terninger(int *terning_antal);
void rul_terning(int terning_antal, int terning[]);
/* Funktion der ruller for 1-6 */
void oeverste_del(int oejne, int terning_antal, int terning[], int point[]);
/* Funktioner for den nedre del */
void et_par(int terning_antal, int terning[], int taeller[], int point[]);
void to_par(int terning_antal, int terning[], int taeller[], int point[]);
void tre_ens(int terning_antal, int terning[], int taeller[], int point[]);
void fire_ens(int terning_antal, int terning[], int taeller[], int point[]);
void lille_straight(int terning_antal, int terning[], int taeller[], int point[]);
void stor_straight(int terning_antal, int terning[], int taeller[], int point[]);
void fuldt_hus(int terning_antal, int terning[], int taeller[], int point[]);
void chance(int terning_antal, int terning[], int taeller[], int point[]);
void yatzy(int terning_antal, int terning[], int taeller[], int point[]);
/* Funktionen for q sort til at sortere terningerne fra størst til mindst */
int sorter_nedafgaeende(const void *ip1, const void *ip2);
/* Funktion der tæller hvor mange af hver terning der er */
void terning_taeller(int terning_antal, int terning[], int taeller[]);
/* Generelle program funktioner */
void resultat_tavle(int terning_antal, int terning[], int taeller[], int point[], int *score, int *bonus);
void yatzy_program(int *terning_antal, int taeller[], int point[], int *score, int *bonus, bool *koer, char *fortsaet_spil);

int main(void)
{
  srand(time(NULL)); /* Starter den tilfældige tal generator */
                     /* Dette skal kun gøres en gang */
  int terning_antal = 0, rounds = 15, score = 0, omgang;
  int taeller[6];
  int en = 0, to = 0, tre = 0, fire = 0, fem = 0, seks = 0;
  int point[rounds]; /* Point array bliver initialiseret to mængden af runder */
  int bonus = 0;
  bool koer = true;
  char fortsaet_spil;

  yatzy_program(&terning_antal, taeller, point, &score, &bonus, &koer, &fortsaet_spil);
  return 0;
}

void yatzy_program(int *terning_antal, int taeller[], int point[], int *score, int *bonus, bool *koer, char *fortsaet_spil)
{
  while (*koer == true)
  {
    *score = 0;
    input_terninger(&*terning_antal);
    int terning[*terning_antal]; /* Laver et array der indeholder 'terning_antal' mængde af værdier */
    resultat_tavle(*terning_antal, terning, taeller, point, &*score, &*bonus);
    printf("Vil du spille igen? (y/n)\n");
    scanf(" %c", &*fortsaet_spil);
    if (*fortsaet_spil == 'y')
    {
      *terning_antal = 0;
    }
    else if (*fortsaet_spil == 'n')
    {
      *koer = false;
      printf("Tak for at spille, kom igen en anden gang!\n");
    }
  }
}

void resultat_tavle(int terning_antal, int terning[], int taeller[], int point[], int *score, int *bonus)
{
  int omgang;
  for (omgang = 0; omgang < 6; omgang++)
  {
    rul_terning(terning_antal, terning);
    oeverste_del(omgang + 1, terning_antal, terning, point);
    printf("Score for at rulle for %d: %d\n"
           "--------------------------------------------------------------------------\n",
           omgang + 1, point[omgang]);
  }

  for (omgang = 0; omgang < 6; omgang++)
  {
    *score += point[omgang];
  }
  printf("Score fra øverste del: %d\n", *score);
  if (*score > 62)
  {
    *bonus = 50;
    printf("Du scorede 63 eller mere i den øverste section, her er 50 bonus point!\n"
           "--------------------------------------------------------------------------\n");
  }
  else
  {
    printf("Du scorede ikke 63 eller mere, ingen bonus point.\n"
           "--------------------------------------------------------------------------\n");
  }
  rul_terning(terning_antal, terning);
  et_par(terning_antal, terning, taeller, point);
  printf("Score for et par: %d\n"
         "--------------------------------------------------------------------------\n",
         point[6]);
  rul_terning(terning_antal, terning);
  to_par(terning_antal, terning, taeller, point);
  printf("Score for to par: %d\n"
         "--------------------------------------------------------------------------\n",
         point[7]);
  rul_terning(terning_antal, terning);
  tre_ens(terning_antal, terning, taeller, point);
  printf("Score for tre ens: %d\n"
         "--------------------------------------------------------------------------\n",
         point[8]);
  rul_terning(terning_antal, terning);
  fire_ens(terning_antal, terning, taeller, point);
  printf("Score for fire ens: %d\n"
         "--------------------------------------------------------------------------\n",
         point[9]);
  rul_terning(terning_antal, terning);
  lille_straight(terning_antal, terning, taeller, point);
  printf("Score for lille straight: %d\n"
         "--------------------------------------------------------------------------\n",
         point[10]);
  rul_terning(terning_antal, terning);
  stor_straight(terning_antal, terning, taeller, point);
  printf("Score for stor straight: %d\n"
         "--------------------------------------------------------------------------\n",
         point[11]);
  rul_terning(terning_antal, terning);
  fuldt_hus(terning_antal, terning, taeller, point);
  printf("Score for fuldt hus: %d\n"
         "--------------------------------------------------------------------------\n",
         point[12]);
  rul_terning(terning_antal, terning);
  chance(terning_antal, terning, taeller, point);
  printf("Score for chance: %d\n"
         "--------------------------------------------------------------------------\n",
         point[13]);
  rul_terning(terning_antal, terning);
  yatzy(terning_antal, terning, taeller, point);
  printf("Score for yatzy: %d\n"
         "--------------------------------------------------------------------------\n",
         point[14]);
  for (omgang = 6; omgang < 15; omgang++)
  {
    *score += point[omgang];
  }
  printf("Total score med bonus(hvis du fik dette): %d\n", *score + *bonus);
}

void rul_terning(int terning_antal, int terning[])
{ /* terning_antal = mængde af terninger kastet, terning[] er arrayet hvor hver ternings værdi bliver tildelt til */
  int omgang;
  for (omgang = 0; omgang < terning_antal; omgang++)
  {
    terning[omgang] = (rand() % TERNING_MAX_OEJNE) + 1;
    if (omgang == terning_antal - 1) /* Dette sørger for at den ikke vil have komme efter det sidste tal */
    {
      printf("%d", terning_antal - 1);
    }
    else
    {
      printf("%d, ", terning[omgang]);
    }
  }
  printf("\n");
}

void input_terninger(int *terning_antal)
{ /* Denne funktion beder brugeren inputte mængden af terninger større end 4 */
  printf("Hvor mange terninger vil du rulle? ");
  while (*terning_antal < 5)
  {
    printf("Venligst input et heltal større end 4: ");
    scanf(" %d", &*terning_antal);
  }
}

void oeverste_del(int oejne, int terning_antal, int terning[], int point[])
{
  point[oejne - 1] = 0; /* -1 på oejne er fordi den første værdi i et array er addreseret som point[0] */
  int maxpoint = 0, omgang;
  for (omgang = 0; omgang < terning_antal; omgang++)
  {
    if (terning[omgang] == oejne && maxpoint < 5)
    {
      point[oejne - 1] += oejne;
      maxpoint++;
    }
    else if (maxpoint == 5)
    {
      omgang = terning_antal;
    }
  }
}

void et_par(int terning_antal, int terning[], int taeller[], int point[])
{
  terning_taeller(terning_antal, terning, taeller);
  int omgang;
  point[6] = 0;

  for (omgang = 5; omgang > -1; omgang--)
  {
    if (taeller[omgang] > 1 && terning_antal - taeller[omgang] > 2)
    {
      point[6] = (omgang + 1) * 2;
      omgang = -1;
    }
  }
}

void to_par(int terning_antal, int terning[], int taeller[], int point[])
{
  terning_taeller(terning_antal, terning, taeller);
  int omgang_1, omgang_2;
  point[7] = 0;
  for (omgang_1 = 5; omgang_1 > -1; omgang_1--)
  {
    for (omgang_2 = 5; omgang_2 > -1; omgang_2--)
    {
      if (taeller[omgang_1] > 1 && taeller[omgang_2] > 1 && omgang_1 != omgang_2 && (terning_antal - taeller[omgang_1] - taeller[omgang_2]) > 0)
      {
        point[7] = (omgang_1 + omgang_2 + 2) * 2;
        omgang_1 = -1;
        omgang_2 = -1;
      }
    }
  }
}

void tre_ens(int terning_antal, int terning[], int taeller[], int point[])
{
  terning_taeller(terning_antal, terning, taeller);
  int omgang;
  point[8] = 0;
  for (omgang = 5; omgang > -1; omgang--)
  {
    if (taeller[omgang] > 2)
    {
      point[8] = (omgang + 1) * 3;
      omgang = -1;
    }
  }
}

void fire_ens(int terning_antal, int terning[], int taeller[], int point[])
{
  terning_taeller(terning_antal, terning, taeller);
  int omgang;
  point[9] = 0;
  for (omgang = 5; omgang > -1; omgang--)
  {
    if (taeller[omgang] > 3)
    {
      point[9] = (omgang + 1) * 4;
      omgang = -1;
    }
  }
}

void lille_straight(int terning_antal, int terning[], int taeller[], int point[])
{
  terning_taeller(terning_antal, terning, taeller);
  point[10] = 0;
  if (taeller[4] > 0 && taeller[3] > 0 && taeller[2] > 0 && taeller[1] > 0 && taeller[0] > 0)
  {
    point[10] = 15;
  }
}

void stor_straight(int terning_antal, int terning[], int taeller[], int point[])
{
  terning_taeller(terning_antal, terning, taeller);
  point[11] = 0;
  if (taeller[5] > 0 && taeller[4] > 0 && taeller[3] > 0 && taeller[2] > 0 && taeller[1] > 0)
  {
    point[11] = 20;
  }
}

void fuldt_hus(int terning_antal, int terning[], int taeller[], int point[])
{
  terning_taeller(terning_antal, terning, taeller);
  int omgang_1, omgang_2;
  point[12] = 0;
  for (omgang_1 = 5; omgang_1 > -1; omgang_1--)
  {
    for (omgang_2 = 5; omgang_2 > -1; omgang_2--)
    {
      if (taeller[omgang_1] > 2 && terning_antal - taeller[omgang_1] > 1)
      {
        if (taeller[omgang_2] > 1 && omgang_1 != omgang_2)
        {
          point[12] = (omgang_1 + 1) * 3 + (omgang_2 + 1) * 2;
          omgang_1 = -1;
          omgang_2 = -1;
        }
      }
    }
  }
}

void chance(int terning_antal, int terning[], int taeller[], int point[])
{
  terning_taeller(terning_antal, terning, taeller);
  qsort(terning, terning_antal, sizeof(int), sorter_nedafgaeende);
  int omgang;
  point[13] = 0;
  for (omgang = 0; omgang < 5; omgang++)
  {
    point[13] += terning[omgang];
  }
}

void yatzy(int terning_antal, int terning[], int taeller[], int point[])
{
  terning_taeller(terning_antal, terning, taeller);
  point[14] = 0;
  int omgang;
  for (omgang = 0; omgang < 5; omgang++)
  {
    if (taeller[omgang] > 4)
    {
      point[14] = 50;
      omgang = 5;
    }
  }
}

void terning_taeller(int terning_antal, int terning[], int taeller[])
{
  int omgang;
  for (omgang = 0; omgang < 6; omgang++)
  {
    taeller[omgang] = 0;
  }
  for (omgang = 0; omgang < terning_antal; omgang++)
  {
    if (terning[omgang] == 1)
    {
      taeller[0]++;
    }
    else if (terning[omgang] == 2)
    {
      taeller[1]++;
    }
    else if (terning[omgang] == 3)
    {
      taeller[2]++;
    }
    else if (terning[omgang] == 4)
    {
      taeller[3]++;
    }
    else if (terning[omgang] == 5)
    {
      taeller[4]++;
    }
    else if (terning[omgang] == 6)
    {
      taeller[5]++;
    }
  }
}

int sorter_nedafgaeende(const void *ip1, const void *ip2)
{
  int resultat;
  int *ipi1 = (int *)ip1,
      *ipi2 = (int *)ip2;

  if (*ipi1 < *ipi2)
    resultat = 1;
  else if (*ipi1 > *ipi2)
    resultat = -1;
  else
    resultat = 0;

  return resultat;
}
