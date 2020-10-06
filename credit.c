#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int num = 0;
    int len = 0;
    int last = 0;
    int checksum = 0;
    
    long card_number = get_long("Enter your credit card number\n");
    
    long x = card_number;
    while (x != 0) //find length of credit card number
    {
        x /= 10;
        len++;
    }
    
    long first2 = card_number;
    while (first2 >= 100) //find first 2 digits of the card number
    {
        first2 /= 10;
    }
    
    long first = card_number;
    while (first >= 10) //find first digit of card number
    {
        first /= 10;
    }
    
    long other = card_number;
    while (other != 0) //add every other number multiplied by 2
    {
        other = other / 10;
        num = other % 10;
        num *= 2;
        if (num >= 10)
        {
            while (num != 0)
            {
                checksum += num % 10;
                num /= 10;
            }
        }
        else
        {
            checksum += num;
        }
        
        other /= 10;
    }
    
    while (card_number != 0) // adds the rest of the numbers to the sum
    {
        num = card_number % 10;
        checksum += num;
        card_number /= 100;
    }
    
    last = checksum % 10;
    
    if (last == 0) //checksum ends with 0
    {
        if (len == 15 && (first2 == 34 || first2 == 37)) //checks if card is American Express
        {
            printf("AMEX\n");
        }
        else if (len == 16 && first2 >= 51 && first2 <= 55) //checks if card is MasterCard
        {
            printf("MASTERCARD\n");
        }
        else if ((len == 13 || len == 16) && first == 4) //checks if card is Visa
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    
}