
#include <stdio.h>

int main()
{
    int message=25;
    int k1=7,k2=11;
    int dsa1,dsa2,rsa1,rsa2;

    dsa1=(message+k1)%97;
    dsa2=(message+k2)%97;

    rsa1=(message*message)%97;
    rsa2=(message*message)%97;

    printf("Message: %d\n",message);
    printf("DSA-like signature 1: %d\n",dsa1);
    printf("DSA-like signature 2: %d\n",dsa2);
    printf("RSA-like signature 1: %d\n",rsa1);
    printf("RSA-like signature 2: %d\n",rsa2);

    return 0;
}

