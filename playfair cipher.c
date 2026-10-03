#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void createMatrix(char key[])
{
    int used[26] = {0};
    int i, k = 0;
    char ch;

    for (i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if (ch == 'J')
            ch = 'I';

        if (!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++)
    {
        if (ch == 'J')
            continue;

        if (!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}

void findPosition(char ch, int *row, int *col)
{
    int i, j;

    ch = toupper(ch);

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(char text[])
{
    int i;
    int r1, c1, r2, c2;

    for (i = 0; text[i] != '\0'; i += 2)
    {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2)
        {
            c1 = (c1 + 1) % 5;
            c2 = (c2 + 1) % 5;
        }
        else if (c1 == c2)
        {
            r1 = (r1 + 1) % 5;
            r2 = (r2 + 1) % 5;
        }
        else
        {
            int temp = c1;
            c1 = c2;
            c2 = temp;
        }

        text[i] = matrix[r1][c1];
        text[i + 1] = matrix[r2][c2];
    }
}

int main()
{
    char key[30];
    char text[100];
    int i;

    printf("Enter key: ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf("%s", text);

    createMatrix(key);

    printf("\nPlayfair Matrix:\n");

    for (i = 0; i < 5; i++)
    {
        printf("%c %c %c %c %c\n",
               matrix[i][0], matrix[i][1], matrix[i][2],
               matrix[i][3], matrix[i][4]);
    }

    if (strlen(text) % 2 != 0)
        strcat(text, "X");

    encrypt(text);

    printf("\nEncrypted text: %s\n", text);

    return 0;
}
