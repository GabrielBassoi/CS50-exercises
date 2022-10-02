#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int letters(string text1, int len1, int i1, int len3);
int words(string text1, int len1, int i1, int space1);
int sentences(string text1, int len1, int i1, int point);
void calc(float letter, float sentence, float word);

int main(void)
{
    //Variables
    int le;
    int len;
    int lette = 0;
    int i = 0;
    int space = 0;
    int points = 0;
    
    //Question?
    string text = get_string("Text: ");
    len = strlen(text);
    
    //Capturando os resultados
    float le1 = letters(text, len, i, lette);
    float wor = words(text, len, i, space);
    float sen = sentences(text, len, i, points);
    calc(le1, sen, wor);
}

//Verify how many letters are in the text------------------------------------
int letters(string text1, int len1, int i1, int letter)
{
    //Verify how many letters are in the text
    for (int n = 0; n < len1; n++)
    {
        char k = text1[n];
        i1 = k;
        if ((i1 >= 65 && i1 <= 90) || (i1 >= 97 && i1 <= 122))
        {
            letter++;
        }
    }
    return letter;
}

//Verify how many words are in the text-----------------------------------
int words(string text1, int len1, int i1, int space1)
{
    //Verify how many words are in the text
    for (int n = 0; n < len1; n++)
    {
        char k = text1[n];
        i1 = k;
        if (i1 == 32)
        {
            space1++;
        }

    }
    return space1 + 1;
}

//Verify how many sentences are in the text------------------------------------
int sentences(string text1, int len1, int i1, int point)
{
    //Verify how many sentences are in the text
    for (int n = 0; n < len1; n++)
    {
        char k = text1[n];
        i1 = k;
        if (i1 == 46 || i1 == 63 || i1 == 33)
        {
            point++;
        }
    }
    return point;
}

//Caulculate and verify the Grade-------------------------------------------
void calc(float letter, float sentence, float word)
{
    //Caulculate and verify the Grade
    float l = letter / word * 100;
    float s = sentence / word * 100;
    float index = (0.0588 * l) - (0.296 * s) - 15.8;
    int re = round(index);

    if (re < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (re >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", re);
    }
}