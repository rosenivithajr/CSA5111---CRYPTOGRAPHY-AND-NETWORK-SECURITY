
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void caesar(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            text[i] = (char)(base + (text[i] - base + shift + 26) % 26);
        }
    }
}

int main(void) {
    char text[1000];
    int shift, choice;

    printf("Enter text: ");
    if (!fgets(text, sizeof(text), stdin)) return 1;
    text[strcspn(text, "\n")] = '\0';

    printf("Enter shift (0-25): ");
    if (scanf("%d", &shift) != 1) return 1;
    shift = (shift % 26 + 26) % 26;

    printf("1. Encrypt  2. Decrypt\nChoice: ");
    if (scanf("%d", &choice) != 1) return 1;

    if (choice == 2) shift = (26 - shift) % 26;
    else if (choice != 1) {
        printf("Invalid choice\n");
        return 1;
    }

    caesar(text, shift);
    printf("Result: %s\n", text);
    return 0;
}

