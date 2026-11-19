
#include <stdio.h>

int main()
{
    char plaintext[65];
    char key[57];

    printf("Enter 64-bit plaintext (binary): ");
    scanf("%64s",plaintext);

    printf("Enter 56-bit key (binary): ");
    scanf("%56s",key);

    if(strlen(plaintext)!=64 || strlen(key)!=56)
    {
        printf("Invalid input length.\n");
        return 0;
    }

    printf("\nDES block size: 64 bits\n");
    printf("Effective key size: 56 bits\n");
    printf("Plaintext: %s\n",plaintext);
    printf("Key: %s\n",key);
    printf("A full DES implementation is required to produce ciphertext.\n");

    return 0;
}

