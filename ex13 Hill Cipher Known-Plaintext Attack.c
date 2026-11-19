
#include <stdio.h>

int mod26(int x)
{
    return (x % 26 + 26) % 26;
}

int main()
{
    int P[2][2] = {{7, 11}, {4, 15}};
    int C[2][2] = {{7, 0}, {8, 19}};
    int inv[2][2], K[2][2];
    int det, detInv, i, j;

    det = mod26(P[0][0] * P[1][1]
              - P[0][1] * P[1][0]);

    detInv = -1;
    for (i = 1; i < 26; i++) {
        if (mod26(det * i) == 1) {
            detInv = i;
            break;
        }
    }

    if (detInv == -1) {
        printf("Plaintext matrix is not invertible\n");
        return 1;
    }

    inv[0][0] = mod26(detInv * P[1][1]);
    inv[0][1] = mod26(-detInv * P[0][1]);
    inv[1][0] = mod26(-detInv * P[1][0]);
    inv[1][1] = mod26(detInv * P[0][0]);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            K[i][j] = mod26(
                C[i][0] * inv[0][j] +
                C[i][1] * inv[1][j]);
        }
    }

    printf("Recovered Hill key:\n");
    for (i = 0; i < 2; i++)
        printf("%d %d\n", K[i][0], K[i][1]);

    return 0;
}

