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
    humans = (human *)(malloc(sizeof(human)));

    do
    {
        SetHuman(humans, counts);
        counts++;
        humans = (human *)(realloc(humans, sizeof(human) * (counts + 1)));
    } while (AskNew());

    for (int i = 0; i < counts; i++)
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
    char buf_name[32];// name buffer
    char buf_age[32];// age buffer
    char buf_gender[32];// gender buffer

    printf("/////////////////\n");
    printf("// Human No.%d //\n", human_no);
    printf("/////////////////\n");
    printf("Name > ");
    scanf("%s", temp_name);
    printf("Age > ");
    //scanf("%d", &temp_age);
    scanf("%d%*c", &temp_age);
    printf("gender > ");
    //scanf("%c", &temp_gender);
    scanf("%c%*c", &temp_gender);

    // Case fgets
    //printf("/////////////////\n");
    //printf("// Human No.%d //\n", human_no);
    //printf("/////////////////\n");
    //printf("Name > ");
    //fgets(buf_name, sizeof(buf_name), stdin);
    //strcpy(temp_name, buf_name);// Copy buffer to name

    //printf("Age > ");
    //fgets(buf_age, sizeof(buf_age), stdin);
    //temp_age = atoi(buf_age);// Copy buffet to age

    //printf("gender > ");
    //fgets(buf_gender, sizeof(char), stdin);
    //temp_gender = (char)(buf_gender[0]);

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
    char buffer[32];
    char answer;


    /*Containing bug
    do
    {
        printf("Do you want to make new human? (y/n) >");
        scanf("%c", &answer);
        printf("State of answer = %c\n", answer);
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
    */

    // Modified code
    do
    {
        printf("Do you want to make new human? (y/n) >");
        fgets(buffer, sizeof(buffer), stdin);
        answer = (char)(buffer[0]);
        if (answer == 'y')
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
        }
        else
        {
            IsCORRECT = false;
        }
    } while (!IsCORRECT);

    return FLAG;
}