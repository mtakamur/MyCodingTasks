#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct human_tab
{
    char NAME[10];
    int AGE;
} Human;

void MakeHuman(Human* target);
void ShowHuman(Human* target);

int main(void)
{
    Human *person;
    Human hito;

    person = &hito;

    printf("Address of object hito = %p\n", &hito);
    printf("Address of pointer person = %p\n", person);

    MakeHuman(person);
    ShowHuman(person);
    return 0;
}

void MakeHuman(Human* target)
{
    char name[10];
    int age = 0;

    printf("Name > ");
    scanf("%s", name);

    printf("\nAge > ");
    scanf("%d", &age);

    //target->NAME = name;
    sprintf(target->NAME, "%s", name);
    target->AGE = age;
    return;
}

void ShowHuman(Human* target)
{
    printf("Name = %s\n", target->NAME);
    printf("Age = %d\n", target->AGE);
    return;
}