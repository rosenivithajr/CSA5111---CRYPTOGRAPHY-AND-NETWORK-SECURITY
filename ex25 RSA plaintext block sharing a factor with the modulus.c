
#include <stdio.h>

int gcd(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int n,m,g;

    printf("Enter RSA modulus n: ");
    scanf("%d",&n);

    printf("Enter plaintext block m: ");
    scanf("%d",&m);

    g=gcd(n,m);

    printf("GCD(m,n) = %d\n",g);

    if(g>1 && g<n)
    {
        printf("A non-trivial factor of n is found.\n");
        printf("RSA modulus can be factored.\n");
        printf("The private key can then be calculated.\n");
    }
    else
    {
        printf("No non-trivial factor found.\n");
    }

    return 0;
}

