#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height, i, j, k;
    
    do
    {
        printf("What's the height of your pyramid?\n"); //ask for user input of height
        scanf("%d", &height);
    }
    while (height <= 0 || height > 8); //asks the user again when he enters an invalid valid
    
    for (i = 1; i <= height; i++)
    {
        for (j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        for (k = 1; k < i + 1; k++)
        {
            printf("#");    //print the hash
        }
        printf("\n");
    }
    
}