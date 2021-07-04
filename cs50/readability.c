// to find the readability of a writing 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //input string
    string text = get_string("Text: ");
    int n = strlen(text);
    int l_c = 0;
    int w_c = 1; //we count spaces to get word count,first word will be before space
    int s_c = 0;
    for (int i = 0; i < n; i++)
    {
        //letter count
        if (isupper(text[i]) || islower(text[i]))
        {
            l_c++;
        }
        //word count
        if (text[i] == ' ')
        {
            w_c++;
        }
        //sentence count
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s_c++;
        }
    }
    //Coleman-Liau index is computed using the formula:
    float L = (float) l_c / w_c * 100;
    float S = (float) s_c / w_c * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}
