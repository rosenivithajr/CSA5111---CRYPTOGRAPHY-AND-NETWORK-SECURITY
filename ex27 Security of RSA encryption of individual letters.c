
#include <stdio.h>

long long modpow(long long a, long long e, long long n)
{
    long long r=1;

    a=a%n;
    while(e>0)
    {
        if(e%2==1)
            r=(r*a)%n;

        a=(a*a)%n;
        e=e/2;
    }

    return r;
}

int main()
{
    long long e,n,c;
    int i;

    printf("Enter public exponent e: ");
    scanf("%lld",&e);

    printf("Enter modulus n: ");
    scanf("%lld",&n);

    printf("Enter ciphertext block: ");
    scanf("%lld",&c);

    printf("\nPossible plaintext letters:\n");

    for(i=0;i<26;i++)
    {
        if(modpow(i,e,n)==c)
            printf("Letter value %d\n",i);
    }

    printf("\nA = 0, B = 1, ..., Z = 25\n");

    return 0;
}

