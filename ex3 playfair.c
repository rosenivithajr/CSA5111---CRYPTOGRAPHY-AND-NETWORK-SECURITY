
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5];

void build(char key[])
{
    int used[26] = {0};
    int i, k = 0, pass;
    char c;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    used['J' - 'A'] = 1;

    for (pass = 0; pass < 2; pass++) {
        char *s = pass == 0 ? key : alphabet;

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
    char key[100], text[500], p[1000], out[1000];
    char a, b;
    int i, n = 0, m = 0;
    int r1, c1, r2, c2;

    printf("Enter key: ");
    scanf("%99s", key);

    build(key);

    printf("Enter plaintext: ");
    scanf(" %499[^\n]", text);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            a = (char)toupper((unsigned char)text[i]);
            if (a == 'J')
                a = 'I';
            p[n++] = a;
        }
    }

    for (i = 0; i < n;) {
        a = p[i++];

        if (i == n)
            b = (a == 'X') ? 'Q' : 'X';
        else if (p[i] == a)
            b = (a == 'X') ? 'Q' : 'X';
        else
            b = p[i++];

        locate(a, &r1, &c1);
        locate(b, &r2, &c2);

        if (r1 == r2) {
            out[m++] = mat[r1][(c1 + 1) % 5];
            out[m++] = mat[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            out[m++] = mat[(r1 + 1) % 5][c1];
            out[m++] = mat[(r2 + 1) % 5][c2];
        } else {
            out[m++] = mat[r1][c2];
            out[m++] = mat[r2][c1];
        }
    }

    out[m] = '\0';
    printf("Ciphertext: %s\n", out);

    return 0;
}

