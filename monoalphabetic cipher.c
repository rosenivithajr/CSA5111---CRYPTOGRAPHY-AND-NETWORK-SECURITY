#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], char key[])
{
    int i;
    
    for (i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]))
            text[i] = toupper(key[text[i] - 'A']);

        else if (islower(text[i]))
            text[i] = tolower(key[text[i] - 'a']);
    }
}

void decrypt(char text[], char key[])
{
    int i, j;
    char ch;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            ch = toupper(text[i]);

            for (j = 0; j < 26; j++)
            {
                if (key[j] == ch)
                {
                    if (isupper(text[i]))
                        text[i] = 'A' + j;
                    else
                        text[i] = 'a' + j;

                    break;
                }
            }
        }
    }
}

int main()
{
    char text[100];
    char key[27];

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the 26-letter substitution key: ");
    scanf("%26s", key);

    if (strlen(key) != 26)
    {
        printf("Error: Key must contain exactly 26 letters.\n");
        return 1;
    }

    encrypt(text, key);
    printf("Encrypted text: %s", text);

    decrypt(text, key);
    printf("Decrypted text: %s", text);

    return 0;
}
