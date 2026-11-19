
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a,int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    char text[100];
    int a,b,i;

    printf("Enter plaintext: ");
    scanf("%99s",text);

    printf("Enter a and b: ");
    scanf("%d%d",&a,&b);

    a=(a%26+26)%26;
    b=(b%26+26)%26;

    if(gcd(a,26)!=1)
    {
        printf("Invalid key: encryption is not one-to-one.\n");
        return 0;
    }

    printf("Ciphertext: ");
    for(i=0;text[i]!='\0';i++)
    {
        char ch=(char)toupper((unsigned char)text[i]);

        if(ch>='A' && ch<='Z')
            printf("%c",'A'+(a*(ch-'A')+b)%26);
        else
            printf("%c",ch);
    }

    printf("\n");
    return 0;
}

