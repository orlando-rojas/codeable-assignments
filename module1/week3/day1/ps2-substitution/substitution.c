#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, char *argv[])
{


    
    if (argc != 2)
    {
        printf("Usage: ./substitution 26-char-key\n");
        return 1;
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Usage: ./substitution 26-char-key\n");
        return 1;
    }

    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        else
        {
            // If its lowercase, make it uppercase
            if (key[i] >= 97 && key[i] <= 122)
            {
                key[i] = (key[i] - 97) % 26 + 65;
            }
        }

        if (i > 0)
        {
            for (int j = 0; j < i; j++)
            {
                // If they keys are duplicated, exit
                if (key[i] == key[j])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }

            }
        }
    }

    char *text = "";
    // Validate the message
    while (*text == '\0' || *text == '\40')
    {
        text = get_string("plaintext: ");
    }

    char *c = "";
    int i = 0;

    // While is not the end and not null
    while (text[i] != '\0')
    {
        c = &text[i];
        // If it is uppercase
        if (*c >= 65 && *c <= 90)
        {
            text[i] = key[(*c - 65)];
        }
        // If it is lowercase
        if (*c >= 97 && *c <= 122)
        {
            // Get the new value and make it lowercase
            text[i] = key[(*c - 97)] + 32;
        }

        i++;
    }

    // Output transformed text
    printf("ciphertext: %s\n", text);

    return 0;
}