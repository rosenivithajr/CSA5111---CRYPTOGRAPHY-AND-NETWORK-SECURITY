#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int a)
{
    int i;

    for (i = 1; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
            return i;
    }

    return -1;
}

void encrypt(char text[], int a, int b)
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]))
            text[i] = ((a * (text[i] - 'A') + b) % 26) + 'A';

        else if (islower(text[i]))
            text[i] = ((a * (text[i] - 'a') + b) % 26) + 'a';
    }
}

void decrypt(char text[], int a, int b)
{
    int i, a_inv;

    a_inv = modInverse(a);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]))
            text[i] = (a_inv * ((text[i] - 'A') - b + 26) % 26) + 'A';

        else if (islower(text[i]))
            text[i] = (a_inv * ((text[i] - 'a') - b + 26) % 26) + 'a';
    }
}

int main()
{
    char text[100];
    int a, b;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter values of a and b: ");
    scanf("%d %d", &a, &b);

    if (gcd(a, 26) != 1)
    {
        printf("Invalid value of a. It must be coprime with 26.\n");
        return 1;
    }

    b = b % 26;

    encrypt(text, a, b);
    printf("Encrypted text: %s", text);

    decrypt(text, a, b);
    printf("Decrypted text: %s", text);

    return 0;
}
