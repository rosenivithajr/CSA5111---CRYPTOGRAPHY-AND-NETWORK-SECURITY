
#include <stdio.h>

long long power(long long a, long long b, long long q)
{
    long long r=1;

    a=a%q;
    while(b>0)
    {
        if(b%2==1)
            r=(r*a)%q;

        a=(a*a)%q;
        b=b/2;
    }

    return r;
}

int main()
{
    long long a,q,x,y,A,B,key1,key2;
    long long altA,altB,altKey1,altKey2;

    printf("Enter public base a and prime q: ");
    scanf("%lld%lld",&a,&q);

    printf("Enter Alice's secret x: ");
    scanf("%lld",&x);

    printf("Enter Bob's secret y: ");
    scanf("%lld",&y);

    A=power(a,x,q);
    B=power(a,y,q);

    key1=power(B,x,q);
    key2=power(A,y,q);

    printf("\nDiffie-Hellman:\n");
    printf("Alice sends: %lld\n",A);
    printf("Bob sends: %lld\n",B);
    printf("Alice's shared key: %lld\n",key1);
    printf("Bob's shared key: %lld\n",key2);

    altA=power(x,a,q);
    altB=power(y,a,q);

    altKey1=power(altB,x,q);
    altKey2=power(altA,y,q);

    printf("\nUsing x^a and y^a instead:\n");
    printf("Alice sends: %lld\n",altA);
    printf("Bob sends: %lld\n",altB);
    printf("Alice's result: %lld\n",altKey1);
    printf("Bob's result: %lld\n",altKey2);

    return 0;
}

