#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

bool checkValid(string s);

int main(int argc, string argv[])
{
    int num; //num is the equivalent int to the letter in the alphabet
    string k;
    if (argc != 2) //checks if the user entered invalid command-line arguments
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!checkValid(argv[1]))
    {
        printf("Key must contain 26 alphabetic characters, each letter exactly once.\n");
        return 1;
    }
    
    k = argv[1];
    string plaintext = get_string("plaintext: ");
    
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i])) //uppercase letter 
            {
                num = plaintext[i] - 65;
                plaintext[i] = toupper(k[num]); //replace the letter with the uppercase equivalent from the key
            }
            else if (islower(plaintext[i])) //lowercase letter
            {
                num = plaintext[i] - 97;
                plaintext[i] = tolower(k[num]); //replace the letter with the lowercase equivalent from the key
            }
        }
    }
    
    printf("ciphertext: %s\n", plaintext);

    return 0;
}

bool checkValid(string s)
{
    /*returns true if the command-line argument contains 26 letters and each letter appears once only, false otherwise*/
    if (strlen(s) != 26)
    {
        return false;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(s[i])) //if the argument contains a non alphabetic characters returns false
        {
            return false;
        }

        for (int j = i + 1; j < 25; j++)
        {
            if (s[i] == s[j])
            {
                return false;
            }
        }
    }
    return true;
}