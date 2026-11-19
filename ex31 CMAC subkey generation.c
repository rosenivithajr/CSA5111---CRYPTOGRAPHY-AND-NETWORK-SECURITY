
#include <stdio.h>

void generate(unsigned char b[16], int n)
{
    int i,carry,msb;
    unsigned char r[16];

    msb=b[0]>>7;
    carry=0;

    for(i=n-1;i>=0;i--)
    {
        r[i]=(b[i]<<1)|carry;
        carry=(b[i]>>7)&1;
    }

    if(msb)
    {
        if(n==8)
            r[n-1]^=0x1B;
        else
            r[n-1]^=0x87;
    }

    for(i=0;i<n;i++)
        b[i]=r[i];
}

int main()
{
    unsigned char b[16];
    int i,n;

    printf("Enter block size (64 or 128): ");
    scanf("%d",&n);

    if(n!=64 && n!=128)
    {
        printf("Invalid block size.\n");
        return 0;
    }

    n=n/8;

    printf("Enter %d bytes in hexadecimal:\n",n);
    for(i=0;i<n;i++)
    {
        unsigned int x;
        scanf("%x",&x);
        b[i]=(unsigned char)x;
    }

    generate(b,n);

    printf("Generated subkey: ");
    for(i=0;i<n;i++)
        printf("%02X ",b[i]);

    printf("\n");
    return 0;
}

