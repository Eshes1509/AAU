#include <stdio.h>

int main(void)
{
    char name, name2;
    int age;

    printf("Enter your name:");
    scanf("%c%c", &name, &name2 );

// Here the user is prompted to type in their name.
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Your name is %c%c, and you are %d years old. \n", name, name2, age);

    return(0);
}