#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[32];
    int age;
    char gender;
} human;

int SetHuman(human *address, int human_no);
int ShowHuman(human *address, int human_no);
bool AskNew();

int main(int argc, char *argv[])
{
    human *humans;
    int counts = 0;
    //////////////////////
    // Make first human //
    //////////////////////
    humans = (human*)(malloc(sizeof(human)));

    do
    {
        SetHuman(humans, counts);
        counts++;
        humans = (human*)(realloc(humans, sizeof(human)*(counts+1)));
    } while(AskNew());

    for(int i=0; i<counts; i++)
    {
        ShowHuman(humans, i);
    }

    free(humans);
    return 0;
}

int SetHuman(human *address, int human_no)
{
    char temp_name[32] = "\0";
    int temp_age = 0;
    char temp_gender = 'm';
    printf("/////////////////\n");
    printf("// Human No.%d //\n", human_no);
    printf("/////////////////\n");
    printf("Name > ");
    scanf("%s", temp_name);
    printf("Age > ");
    scanf("%d%*c", &temp_age);
    printf("gender > ");
    scanf("%c%*c", &temp_gender);
    
    //////////////////////////
    // Set human's property //
    //////////////////////////
    strcpy(address[human_no].name, temp_name);
    address[human_no].age = temp_age;
    address[human_no].gender = temp_gender;
    return 0;
}

int ShowHuman(human *address, int human_no)
{
    printf("/////////////////////////////////////\n");
    printf("// Showing property of Human No.%d //\n", human_no);
    printf("/////////////////////////////////////\n");
    printf("Name = %s\n", address[human_no].name);
    printf("Age = %d\n", address[human_no].age);
    printf("Gender = %c\n", address[human_no].gender);
    return 0;
}

bool AskNew()
{
    bool FLAG = false;
    bool IsCORRECT = true;
    char answer;

    do
    {
        printf("Do you want to make new human? (y/n) >");
        scanf("%c", &answer);
        printf("State of answer = %c", answer);
        if(answer == 'y')
        {
            printf("y is selected\n");
            FLAG = true;
            IsCORRECT = true;
        }
        else if (answer == 'n')
        {
            printf("n is selected\n");
            FLAG = false;
            IsCORRECT = true;
        } else
        {
            IsCORRECT = false;
        }
    } while (!IsCORRECT);
    return FLAG;
}