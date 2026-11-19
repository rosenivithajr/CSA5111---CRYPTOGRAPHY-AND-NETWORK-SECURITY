
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[1000], p[1000], c[1000], d[1000];
    int i, n = 0, a, b, x, y;

    printf("Enter plaintext: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i]))
            p[n++] = (char)toupper((unsigned char)text[i]);
    }

    if (n % 2 != 0)
        p[n++] = 'X';
    p[n] = '\0';

    for (i = 0; i < n; i += 2) {
        a = p[i] - 'A';
        b = p[i + 1] - 'A';

        c[i] = (char)('A' + (9 * a + 4 * b) % 26);
        c[i + 1] = (char)('A' + (5 * a + 7 * b) % 26);
    }
    c[n] = '\0';

    /* Inverse key modulo 26: [5 12; 15 25] */
    for (i = 0; i < n; i += 2) {
        x = c[i] - 'A';
        y = c[i + 1] - 'A';

        d[i] = (char)('A' + (5 * x + 12 * y) % 26);
        d[i + 1] = (char)('A' + (15 * x + 25 * y) % 26);
    }
    d[n] = '\0';

    printf("Prepared plaintext: %s\n", p);
    printf("Encrypted text: %s\n", c);
    printf("Decrypted text: %s\n", d);

    return 0;
}

