
#include <stdio.h>

int mod26(int x)
{
    x=x%26;
    if(x<0) x+=26;
    return x;
}

int main()
{
    int p[2][2],c[2][2],det,inv=0;
    int i,j,k,K[2][2];

    printf("Enter plaintext matrix (2x2):\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&p[i][j]);

    printf("Enter ciphertext matrix (2x2):\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&c[i][j]);

    det=mod26(p[0][0]*p[1][1]-p[0][1]*p[1][0]);

    for(i=0;i<26;i++)
        if((det*i)%26==1)
            inv=i;

    if(inv==0)
    {
        printf("Plaintext matrix has no inverse modulo 26.\n");
        return 0;
    }

    {
        int pinv[2][2];
        pinv[0][0]=mod26(p[1][1]*inv);
        pinv[0][1]=mod26(-p[0][1]*inv);
        pinv[1][0]=mod26(-p[1][0]*inv);
        pinv[1][1]=mod26(p[0][0]*inv);

        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
            {
                K[i][j]=0;
                for(k=0;k<2;k++)
                    K[i][j]+=c[i][k]*pinv[k][j];
                K[i][j]=mod26(K[i][j]);
            }
    }

    printf("Recovered key matrix:\n");
    for(i=0;i<2;i++)
        printf("%d %d\n",K[i][0],K[i][1]);

    return 0;
}

