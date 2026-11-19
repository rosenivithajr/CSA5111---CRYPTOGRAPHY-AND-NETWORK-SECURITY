
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Error propagation in ECB and CBC modes\n\n");

    printf("Case 1: A transmitted bit error in C1\n\n");

    printf("ECB:\n");
    printf("P1: corrupted\n");
    printf("P2 and later blocks: unaffected\n\n");

    printf("CBC:\n");
    printf("P1: corrupted\n");
    printf("P2: corresponding bit flipped\n");
    printf("P3 and later blocks: unaffected\n\n");

    printf("Case 2: A bit error in source plaintext P1\n\n");

    printf("ECB:\n");
    printf("Only ciphertext block C1 changes.\n\n");

    printf("CBC:\n");
    printf("C1 and subsequent ciphertext blocks generally change.\n");

    return 0;
}

