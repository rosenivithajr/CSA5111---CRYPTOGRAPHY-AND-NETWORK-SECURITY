
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[1000];
    int shift,i,s;

    printf("Enter ciphertext: ");
    fgets(text,sizeof(text),stdin);

    for(shift=0;shift<26;shift++)
    {
        printf("Shift %2d: ",shift);

        for(i=0;text[i]!='\0';i++)
        {
            char ch=(char)toupper((unsigned char)text[i]);

            if(ch>='A' && ch<='Z')
                putchar('A'+(ch-'A'-shift+26)%26);
            else
                putchar(text[i]);
        }
    }

    return 0;
}

