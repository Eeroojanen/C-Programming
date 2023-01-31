#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_USER_INPUT 15

void display_menu(void);
char ask_command(void);
void read_string(char strl[]);
void print_string(char strl[]);
void to_lower(char strl[]);
void to_upper(char strl[]);
int count_vowels(char strl[],int i);
int count_consonants(char strl[],int i);
void read_file(char strl[]);
void write_file(char strl[]);

int main(void)
{
    char askedcommand;
    int i;
    int count;
    display_menu();
    char strl[MAX_USER_INPUT] = "Hello World";
    askedcommand = ask_command();
    while(askedcommand != 'X')
    {
        switch(askedcommand)
        {
            case 'M':
                display_menu();
                break;
            case 'F':
                read_string(strl);
                break;
            case 'E':
                print_string(strl);
                break;
            case 'D':
                to_lower(strl);
                break;
            case 'C':
                to_upper(strl);
                break;
            case 'A':
                count_vowels(strl,i);
                break;
            case 'B':
                count_consonants(strl,i);
                break;
            
    }
        askedcommand = ask_command();
}
    return 0;
}

int count_consonants(char strl[],int i)
{
    int count = 0;
    int consonants = 0;
       for(i=0;strl[i];i++)  
    {
    	if((strl[i]>=65 && strl[i]<=90)|| (strl[i]>=97 && strl[i]<=122))
    	{
            if(strl[i]=='a'|| strl[i]=='e'||strl[i]=='i'
            ||strl[i]=='o'||strl[i]=='u'||strl[i]=='y'
            ||strl[i]=='A'||strl[i]=='E'||strl[i]=='I'
            ||strl[i]=='O' ||strl[i]=='U'||strl[i]=='Y')
            {
		        count++;
            }
            else
                consonants++;
        }
 	}
    printf("Total number of consonants: = %d\n",consonants);
}

int count_vowels(char strl[],int i)
{
    int count = 0;
    for(i = 0 ; strl[i] ; i++)
    {
        if(strl[i]=='a'|| strl[i]=='e'||strl[i]=='i'||
           strl[i]=='o'|| strl[i]=='u'||strl[i]=='y'||strl[i]=='A'||
           strl[i]=='E'||strl[i]=='I'||strl[i]=='O' ||strl[i]=='U'||strl[i]=='Y')
           {
               count++;
           }
    }
     printf("Total number of vowels: = %d\n",count);
}

void to_upper(char strl[])
{
    int i;
    for(i = 0 ; strl[i] ; i++)
    {
        strl[i] = toupper(strl[i]);
    }
}

void to_lower(char strl[])
{
    int i;
    for(i = 0 ; strl[i] ; i++)
    {
        strl[i] = tolower(strl[i]);
    }
}

void display_menu(void)
{
    printf("A) Count the number of vowels in the string\n");
    printf("B) Count the number of consonants in the string\n");
    printf("C) Convert the string to uppercase\n");
    printf("D) Convert the string to lowercase\n");
    printf("E) Display the current string\n");
    printf("F) Enter another string\n");
    printf("G) Read string from file\n");
    printf("H) Write string to file\n");
    printf("\n");
    printf("M) Display this menu\n");
    printf("X) Exit the program");
}

void read_string(char strl[])
{
    printf("Give string:\n");
    fgets(strl,MAX_USER_INPUT,stdin);
}

void print_string(char strl[])
{
    printf("%s",strl);
}

char ask_command(void)
{
    printf("\nGive Command:");
    char askedcommand[MAX_USER_INPUT];
    fgets(askedcommand,MAX_USER_INPUT,stdin);
    return askedcommand[0];
}