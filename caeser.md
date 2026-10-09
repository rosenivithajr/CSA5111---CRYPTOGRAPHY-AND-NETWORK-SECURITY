#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], int shift)
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]))
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';

        else if (islower(text[i]))
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
    }
}

void decrypt(char text[], int shift)
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]))
            text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';

        else if (islower(text[i]))
            text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
    }
}

int main()
{
    char text[100];
    int shift;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    shift = shift % 26;

    encrypt(text, shift);
    printf("Encrypted text: %s", text);

    decrypt(text, shift);
    printf("Decrypted text: %s", text);

    return 0;
}
