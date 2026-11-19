
#include <stdio.h>
#include <string.h>

int main()
{
    char key[57];
    int pc2[48] = {
        14,17,11,24,1,5,3,28,15,6,21,10,
        23,19,12,4,26,8,16,7,27,20,13,2,
        41,52,31,37,47,55,30,40,51,45,33,48,
        44,49,39,56,34,53,46,42,50,36,29,32
    };
    int i, valid = 1;

    printf("Enter 56-bit shifted key: ");
    if (scanf("%56s", key) != 1)
        return 1;

    if (strlen(key) != 56) {
        printf("Key must contain 56 bits\n");
        return 1;
    }

    for (i = 0; i < 56; i++) {
        if (key[i] != '0' && key[i] != '1')
            valid = 0;
    }

    if (!valid) {
        printf("Invalid binary key\n");
        return 1;
    }

    printf("48-bit subkey: ");
    for (i = 0; i < 48; i++)
        printf("%c", key[pc2[i] - 1]);

    printf("\nFirst 24 bits: ");
    for (i = 0; i < 24; i++)
        printf("%c", key[pc2[i] - 1]);

    printf("\nLast 24 bits: ");
    for (i = 24; i < 48; i++)
        printf("%c", key[pc2[i] - 1]);

    printf("\n");
    return 0;
}

