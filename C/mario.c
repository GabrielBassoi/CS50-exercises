#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height1;
    int num = 0;
    
    //question------------------------------------------------
    do
    {
        height1 = get_int("Pyramid Height: ");
    }
    while (height1 < 1 || height1 > 8);
    
    
    for (int height2 = 0; height2 < height1; height2++)
    {
        //Space 1---------------------------------------------
        for (int space1 = 0; space1 < height1 - height2 - 1; space1++)
        {
            printf(" ");
        }
        
        //Hash 1-----------------------------------------------
        for (int hash1 = 0; hash1 <= height2; hash1++)
        {
            printf("#");
        }
        
        //Space 2----------------------------------------------
        printf("  ");
        
        //Hash 2-----------------------------------------------
        for (int hash2 = 0; hash2 < height2 + 1; hash2++)
        {
            printf("#");
        }
        printf("\n");
    }
}
