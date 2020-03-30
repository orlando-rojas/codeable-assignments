#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    if (argc == 2) {
        int aux = 0;
        int strlength = strlen(argv[1]);
        for (int i = 0; i < strlength; i++) {
            if (isalpha(argv[1][i])) {
                aux++;
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        for (int i = 0; i < strlength; i++) {
            if(aux<=0){
                if (isdigit(argv[1][i])) {
                    int key = atoi(argv[1]);
                    string plaintext = get_string("Plaintext: ");
                    printf("ciphertext: ");
                    for (int j = 0, k = strlen(plaintext); j < k; j++) {
                        if (isupper(plaintext[j])) printf("%c", (((plaintext[j] + key) - 65) % 26) + 65);
                        else if (islower(plaintext[j])) printf("%c", (((plaintext[j] + key) - 97) % 26) + 97);
                        else printf("%c", plaintext[j]);
                    }
                    printf("\n");
                    return 0;
                }
            }
        }
    }
    else {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}