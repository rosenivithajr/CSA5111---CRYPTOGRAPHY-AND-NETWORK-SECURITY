
#include <stdio.h>

int main()
{
    int i;

    printf("DES decryption round-key order:\n");

    for (i = 16; i >= 1; i--)
        printf("K%d ", i);

    printf("\n");
    return 0;
}

