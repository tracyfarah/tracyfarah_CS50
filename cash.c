#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coins = 0;
    float change = 0;
    do
    {
        change = get_float("How much change is owed?\n");
    }
    while (change < 0);
    
    int cents = round(change * 100);
    
    while (cents >= 25)
    {
        cents = cents - 25;
        coins ++;
    }
    
    while (cents >= 10)
    {
        cents = cents - 10;
        coins ++;
    }
    
    while (cents >= 5)
    {
        cents = cents - 5;
        coins ++;
    }
    
    while (cents >= 1)
    {
        cents = cents - 1;
        coins ++;
    }
    
    
    printf("%i\n", coins);
}