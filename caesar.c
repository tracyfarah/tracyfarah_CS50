#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

bool checkValid(string s);

int main(int argc, string argv[])
{
    int k;
    if (argc != 2 || !checkValid(argv[1])) //if the user entered invalid command-line arguments
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    k = atoi(argv[1]); //convert commad-line argument from string to int
    
    string plaintext = get_string("plaintext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i])) //uppercase letter
        {
            plaintext[i] = (((plaintext[i] - 65 + k) % 26) + 65);
        }
        else if (islower(plaintext[i])) //lowercase letter
        {
            plaintext[i] = (((plaintext[i] - 97 + k) % 26) + 97);
        }
            
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

//returns true if all characters are digits, false otherwise
bool checkValid(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}