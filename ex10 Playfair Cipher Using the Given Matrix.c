
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

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
    char text[1000], p[1000], out[2000];
    char a, b;
    int i, n = 0, m = 0;
    int r1, c1, r2, c2;

    printf("Enter plaintext: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

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

