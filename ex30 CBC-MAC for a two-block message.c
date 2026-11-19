
#include <stdio.h>

int main()
{
    int i;
    char X[9]="10101010";
    char T[9]="11001100";
    char second[9],result[9];

    for(i=0;i<8;i++)
        second[i]=(X[i]==T[i])?'0':'1';
    second[8]='\0';

    for(i=0;i<8;i++)
        result[i]=(second[i]==T[i])?'0':'1';
    result[8]='\0';

    printf("First block X       : %s\n",X);
    printf("One-block MAC T     : %s\n",T);
    printf("Second block X XOR T: %s\n",second);
    printf("Final CBC input     : %s\n",result);
    printf("Two-block MAC       : T (same as one-block MAC)\n");

    return 0;
}

