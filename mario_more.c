#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height, i, j, k, l;
    
    do
    {
        printf("What's the height of your pyramid?\n"); //ask for user input of height
        scanf("%d", &height);
    }
    while (height <= 0 || height > 8); //asks the user again when he enters an invalid valid
    
    for (i = 0; i < height; i++)   
    {
        for (j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }   
        
        for (k = height - i; k <= height; k++) //print left pyramid
        {
            printf("#");
                
        }
        printf("  "); //print gap between two half pyramids
          
        for (l = height - i;  l <= height; l++) //print right triangle
        {
            printf("#");
        }
        
        printf("\n");
    }
    
}