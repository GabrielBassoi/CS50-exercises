#include <stdio.h>
#include <cs50.h>

void verify(long c, long len1);

int main(void)
{
    //variables
    long card = get_long("What's the card number? ");
    long duble = 0;
    long n1 = 0;
    long n2 = 0;
    long n3 = 0;
    long num = 0;
    long len = 0;
    long digit = 0;
    long digit2 = 0;
    long digit3 = 0;
    
    //separating card numbers-----------------
    for (; card > 0;)
    {
        //calculate len-------------
        len++;
        digit = card % 10;
        card = (card - digit) / 10;
        
        //math operations---------------
        if (duble == 1)
        {
            n1 = 2 * digit;
            digit2 = n1 % 10;
            n1 = ((n1 - digit2) / 10) + digit2;
            n3 += n1;

            duble--;
        }
        //math operations---------------
        else
        {
            n2 += digit;
            duble++;
        }
        
        //Agency----------------
        if (card < 100 && card > 36)
        {
            num = card;
            if (num < 50 && num > 39)
            {
                num /= 10;
            }
        }
    }
    
    //verifying math operations-----------------
    n3 += n2;
    digit3 = n3 % 10;
    
    if (digit3 == 0)
    {
        verify(num, len);
    }
    else
    {
        printf("INVALID\n");
    }
}

//verifying finally-----------------------------
void verify(long c, long len1)
{
    //Verifying the len and agency number-----------
    if (c == 4 && (len1 == 13 || len1 == 16))
    {
        printf("VISA\n");
    }
    else if (c > 50 && c < 56 && len1 == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (len1 == 15 && (c == 34 || c == 37))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
