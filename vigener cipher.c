#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], char key[])
{
    int i, j = 0;
    int keyLen = strlen(key);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
                text[i] = ((text[i] - 'A' + toupper(key[j]) - 'A') % 26) + 'A';
            else
                text[i] = ((text[i] - 'a' + tolower(key[j]) - 'a') % 26) + 'a';

            j = (j + 1) % keyLen;
        }
    }
}

void decrypt(char text[], char key[])
{
    int i, j = 0;
    int keyLen = strlen(key);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
                text[i] = ((text[i] - 'A' - (toupper(key[j]) - 'A') + 26) % 26) + 'A';
            else
                text[i] = ((text[i] - 'a' - (tolower(key[j]) - 'a') + 26) % 26) + 'a';

            j = (j + 1) % keyLen;
        }
    }
}

int main()
{
    char text[100];
    char key[50];

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    scanf("%49s", key);

    encrypt(text, key);
    printf("Encrypted text: %s", text);

    decrypt(text, key);
    printf("Decrypted text: %s", text);

    return 0;
}
