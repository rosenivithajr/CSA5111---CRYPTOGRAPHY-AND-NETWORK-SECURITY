
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5];

void build(char key[])
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int used[26] = {0};
    int i, k = 0, pass;
    char c;

    used['J' - 'A'] = 1;

    for (pass = 0; pass < 2; pass++) {
        char *s = (pass == 0) ? key : alphabet;

        for (i = 0; s[i] != '\0'; i++) {
            c = (char)toupper((unsigned char)s[i]);

            if (c < 'A' || c > 'Z')
                continue;
            if (c == 'J')
                c = 'I';

            if (!used[c - 'A']) {
                used[c - 'A'] = 1;
                mat[k / 5][k % 5] = c;
                k++;
            }
        }
    }
}

void locate(char c, int *r, int *col)
{
    int i, j;

    if (c == 'J')
        c = 'I';

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (mat[i][j] == c) {
                *r = i;
                *col = j;
                return;
            }
}

int main()
{
    char key[100], text[5000], p[5000];
    int i, n = 0, r1, c1, r2, c2;
    char c;

    printf("Enter key: ");
    if (scanf("%99s", key) != 1)
        return 1;

    build(key);

    printf("Enter ciphertext: ");
    scanf(" %4999[^\n]", text);

    for (i = 0; text[i] != '\0'; i++) {
        c = (char)toupper((unsigned char)text[i]);
        if (c >= 'A' && c <= 'Z') {
            if (c == 'J')
                c = 'I';
            p[n++] = c;
        }
    }

    if (n % 2 != 0) {
        printf("Invalid ciphertext length\n");
        return 1;
    }

    printf("Plaintext: ");

    for (i = 0; i < n; i += 2) {
        locate(p[i], &r1, &c1);
        locate(p[i + 1], &r2, &c2);

        if (r1 == r2) {
            putchar(mat[r1][(c1 + 4) % 5]);
            putchar(mat[r2][(c2 + 4) % 5]);
        } else if (c1 == c2) {
            putchar(mat[(r1 + 4) % 5][c1]);
            putchar(mat[(r2 + 4) % 5][c2]);
        } else {
            putchar(mat[r1][c2]);
            putchar(mat[r2][c1]);
        }
    }

    printf("\n");
    return 0;
}

