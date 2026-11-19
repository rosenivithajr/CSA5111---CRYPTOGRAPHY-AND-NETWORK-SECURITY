#include <stdio.h>

int main()
{
    int bits, block, pad, i;

    printf("Enter plaintext length in bits: ");
    scanf("%d", &bits);

    printf("Enter block/segment size in bits: ");
    scanf("%d", &block);

    if (bits <= 0 || block <= 0)
    {
        printf("Invalid input.\n");
        return 0;
    }

    pad = block - (bits % block);

    if (pad == 0)
        pad = block;

    printf("Padding bits: 1");
    for (i = 1; i < pad; i++)
        printf("0");

    printf("\nNumber of padding bits: %d\n", pad);
    printf("Final message length: %d bits\n", bits + pad);

    return 0;
}
