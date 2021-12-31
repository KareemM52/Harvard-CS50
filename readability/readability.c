#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: ");
    int words, sentences, letters;
    words = 0;
    sentences = 0;
    letters = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentences ++;
        }
        if ((i != n - 1 && s[i] == ' ' && s[i + 1] != ' ') || (i == 0  && s[i] != ' '))
        {
            words ++;
        }
        if (isalpha(s[i]))
        {
            letters ++;
        }
      
    }
    float L = ((float)letters / (float) words) * 100;

    float S = ((float)sentences / (float) words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    
        printf("Grade %i\n", index);
        }
    

