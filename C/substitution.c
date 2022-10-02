#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//--------------------------------------------------------------------------------------------

bool are(int argc1);
bool key_len(int len1);
bool nums(char u1, int nn, int j1, string argv1);


//-----------------------------------------------------------------------------------------------

int main(int argc, string argv[])
{
    char u = '\0';
    char keyl[26];
    int n = 0;
    
    if (!are(argc))
    {
        printf("Usage: ./substitution Key\n");
        return 1;
    }
    string key1 = argv[1];
    int len = strlen(argv[1]);
    
    if (!key_len(len))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    for (int r = 0; r < 26; r++)
    {
        if (isupper(key1[r]))
        {
            keyl[r] = tolower(key1[r]);
        }
        else
        {
            keyl[r] = key1[r];
        }
    }
    for (int j = 0; j < 26; j++)
    {
        if (!nums(u, n, j, argv[1]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        for (int t = 0 + j; t < 26; t++)
        {
            if (keyl[j] == keyl[t + 1])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    
    //----------------------------------------------------------------------------------------
    string text = get_string("plaintext: ");
    char abcl[26];
    char abcu[26];
    char keyu[26];
    int gh = 0;
    int lenn = strlen(text);
    char textf[lenn];
    
    //creating ABC and key upper and lower
    
    for (int zx = 0; zx < 26; zx++)
    {
        abcu[zx] = 65 + zx;
    }
    
    for (int zc = 0; zc < 26; zc++)
    {
        abcl[zc] = 97 + zc;
    }
    
    for (int zv = 0; zv < 26; zv++)
    {
        if (islower(key1[zv]))
        {
            keyu[zv] = toupper(key1[zv]);
        }
        else
        {
            keyu[zv] = key1[zv];
        }
    }
    
    //----------------------------------------------------
    //cripto text
    
    for (int b = 0; b < lenn; b++) 
    {
        gh = text[b];
        if (gh >= 65 && gh <= 90) // isupper
        {
            for (int y = 0; y < 26; y++)
            {
                if (gh == abcu[y])
                {
                    //gh = keyu[y];
                    textf[b] = keyu[y];
                }
            }
            
        }
        else if (gh >= 97 && gh <= 122) // islower
        {
            for (int yf = 0; yf < 26; yf++)
            {
                if (gh == abcl[yf])
                {
                    //gh = keyl[yf];
                    textf[b] = keyl[yf];
                }
            }
        }
        else // points and space
        {
            textf[b] = text[b];
        }
    }
    printf("ciphertext: ");
    for (int z = 0; z < lenn; z++)
    {
        printf("%c", textf[z]);
        
    }
    printf("\n");
    return 0;
}

//------------------------------------------------------------------------------------------------

bool are(int argc1)
{
    if (argc1 == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//----------------------------------------------------------------------------------------------------
bool key_len(int len1)
{
    if (len1 == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//---------------------------------------------------------------------------------------------------

bool nums(char u1, int nn, int j1, string argv1)
{
    u1 = argv1[j1];
    nn = u1;
    if ((nn >= 65 && nn <= 90) || (nn >= 97 && nn <= 122))
    {
        return true;
    }
    else
    {
        return false;
    }
}
