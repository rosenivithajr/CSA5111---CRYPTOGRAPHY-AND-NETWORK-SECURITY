
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[200];
    int key[200],n,i;

    printf("Enter plaintext (no spaces): ");
    scanf("%199s",text);

    n=strlen(text);

    printf("Enter %d key numbers (0-25): ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&key[i]);

        if(key[i]<0 || key[i]>25)
        {
            printf("Invalid key value.\n");
            return 0;
        }
    }

    printf("Ciphertext: ");

    for(i=0;i<n;i++)
    {
        if(!isalpha((unsigned char)text[i]))
        {
            printf("%c",text[i]);
        }
        else
        {
            char ch=(char)toupper((unsigned char)text[i]);
            printf("%c",'A'+((ch-'A'+key[i])%26));
        }
    }

    printf("\n");
    return 0;
}

