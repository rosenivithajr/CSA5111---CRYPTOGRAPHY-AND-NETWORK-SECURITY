
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plain[] = "sendmoremoney";
    char target[] = "cashnotneeded";
    char cipher[100], newKey[100];
    int key[] = {9, 0, 1, 7, 23, 15, 21,
                 14, 11, 11, 2, 8, 9};
    int i, p, t, c, k;

    printf("Plaintext: send more money\n");
    printf("Ciphertext: ");

    for (i = 0; plain[i] != '\0'; i++) {
        p = plain[i] - 'a';
        c = (p + key[i]) % 26;
        cipher[i] = (char)('a' + c);
        printf("%c", cipher[i]);
    }
    cipher[i] = '\0';

    printf("\nNumeric key stream: ");
    for (i = 0; i < 13; i++)
        printf("%d ", key[i]);

    printf("\nNew key for target plaintext: ");
    for (i = 0; i < 13; i++) {
        c = cipher[i] - 'a';
        t = target[i] - 'a';
        k = (c - t + 26) % 26;

        newKey[i] = (char)('a' + k);
        printf("%d ", k);
    }

    newKey[13] = '\0';

    printf("\nNew key as letters: %s\n", newKey);
    printf("Target plaintext: cash not needed\n");

    return 0;
}

