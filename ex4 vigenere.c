
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[500], key[100];
    int i, j = 0, k, x, base, choice, len;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key: ");
    scanf("%99s", key);

    for (i = 0; key[i] != '\0'; i++) {
        if (!isalpha((unsigned char)key[i])) {
            printf("Invalid key\n");
            return 1;
        }
        key[i] = (char)toupper((unsigned char)key[i]);
    }

    len = (int)strlen(key);

    printf("1. Encrypt  2. Decrypt: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice\n");
        return 1;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            x = toupper((unsigned char)text[i]) - 'A';
            k = key[j % len] - 'A';

            if (choice == 1)
                text[i] = (char)(base + (x + k) % 26);
            else
                text[i] = (char)(base + (x - k + 26) % 26);

            j++;
        }
    }

    printf("Result: %s\n", text);
    return 0;
}

