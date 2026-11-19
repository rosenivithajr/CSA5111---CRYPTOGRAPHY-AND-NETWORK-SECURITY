
#include <stdio.h>

int main()
{
    int choice;

    printf("CBC encryption algorithm selection\n");
    printf("1. DES\n");
    printf("2. Triple DES (3DES)\n");
    printf("Choose priority:\n");
    printf("1. Security\n");
    printf("2. Performance\n");
    printf("Choice: ");

    if (scanf("%d", &choice) != 1)
        return 1;

    if (choice == 1) {
        printf("Suggested option: 3DES over DES for legacy systems.\n");
        printf("Note: 3DES is now deprecated for most new systems.\n");
    } else if (choice == 2) {
        printf("DES is generally faster than 3DES.\n");
        printf("Neither is recommended for new designs.\n");
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    printf("For new systems, prefer AES in an appropriate mode.\n");
    return 0;
}

