
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char text[5000];
    int i, x, y, base;

    printf("Enter ciphertext: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            x = toupper((unsigned char)text[i]) - 'A';
            y = (9 * (x - 15 + 26)) % 26;
            text[i] = (char)(base + y);
        }
    }

    printf("Candidate plaintext: %s", text);
    return 0;
}

