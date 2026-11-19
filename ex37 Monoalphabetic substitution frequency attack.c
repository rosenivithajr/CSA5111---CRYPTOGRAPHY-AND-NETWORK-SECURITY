
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[1000];
    char freq[]="ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26]={0},used[26]={0};
    int map[26],i,j,best;

    printf("Enter ciphertext: ");
    fgets(text,sizeof(text),stdin);

    for(i=0;text[i]!='\0';i++)
    {
        char ch=(char)toupper((unsigned char)text[i]);
        if(ch>='A' && ch<='Z')
            count[ch-'A']++;
    }

    for(i=0;i<26;i++)
    {
        best=-1;
        for(j=0;j<26;j++)
        {
            if(!used[j] && (best==-1 || count[j]>count[best]))
                best=j;
        }
        used[best]=1;
        map[best]=freq[i]-'A';
    }

    printf("Possible plaintext:\n");
    for(i=0;text[i]!='\0';i++)
    {
        char ch=(char)toupper((unsigned char)text[i]);
        if(ch>='A' && ch<='Z')
            putchar('A'+map[ch-'A']);
        else
            putchar(text[i]);
    }

    return 0;
}

