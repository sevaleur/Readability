#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    /* gets a string from user */
    string text = get_string("Text: ");

    /* counts letters in the string, and outputs the final count */
    int letterCount = count_letters(text);
    printf("%i letters \n", letterCount);

    /* counts words in the string, and outputs the final count */
    int wordCount = count_words(text);
    printf("%i words \n", wordCount);

    /* counts the sentences in the string, and outputs the final count */
    int sentenceCount = count_sentences(text);
    printf("%i sentences \n", sentenceCount);

    /* calculates the reading level using the Coleman-Liau index */
    float l = ((float)letterCount / (float)wordCount) * 100;
    float s = ((float)sentenceCount / (float)wordCount) * 100;
    float coleman = 0.0588 * l - 0.296 * s - 15.8;
    int index = round(coleman);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
};

/* function that counts the letters */
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
};

/* function that counts the words */
int count_words(string text)
{
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words += 1;
};

/* counts the sentences */
int count_sentences(string text)
{
    int sentences = 0;
    int x = strlen(text);
    for (int i = 0; i < x; i++)
    {
        char a = text[i];
        if (a == '.' || a == '!' || a == '?')
        {
            sentences++;
        }
    }
    return sentences;
};