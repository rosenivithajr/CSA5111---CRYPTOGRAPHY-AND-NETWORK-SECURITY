
#include <stdio.h>

int main()
{
    int bits,block,padding;

    printf("Enter plaintext length in bits: ");
    scanf("%d",&bits);

    printf("Enter block size in bits: ");
    scanf("%d",&block);

    if(bits<=0 || block<=0)
    {
        printf("Invalid input.\n");
        return 0;
    }

    padding=block-(bits%block);

    if(padding==0)
        padding=block;

    printf("Padding length: %d bits\n",padding);
    printf("Padded length: %d bits\n",bits+padding);
    printf("Motivation: unambiguous padding removal.\n");

    return 0;
}

