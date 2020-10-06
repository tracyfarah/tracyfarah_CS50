#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string text = get_string("Enter your text:\n"); //ask user for text input
    
    int letters = count_letters(text);
    
    int words = count_words(text);
    
    int sentences = count_sentences(text); 
    
    float L = (float) letters * 100 / words; //average letters per 100 words
    
    float S = (float) sentences * 100 / words; //average sentences per 100 words
    
    float index = 0.0588 * L - 0.296 * S - 15.8; //calculate Coleman-Liau index
    
    index = round(index);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) index);
    }
}    

//count number of letters in the text
int count_letters(string s)
{
    int letters = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            letters ++;
        }
    }
    return letters;
}

//count number of words in the text
int count_words(string s)
{
    int words = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

//count number of sentences in the text
int count_sentences(string s)
{
    int sentences = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}