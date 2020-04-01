#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letras = 0;
    int palabras = 1;
    int oraciones = 0;

    for (int i = 0; i < strlen(text); i++){
       if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) letras++;
       else if (text[i] == ' ') palabras++;
       else if (text[i] == '.' || text[i] == '!' || text[i] == '?') oraciones++;
    }

    float L = 100 * (float) letras / (float) palabras;
    float S = 100 * (float) oraciones / (float) palabras;

    float grade = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (grade < 16 && grade >= 0)  printf("Grade %i\n", (int) grade);
    else if (grade >= 16) printf("Grade 16+\n");
    else printf("Before Grade 1\n");
}