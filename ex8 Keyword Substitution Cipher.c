
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char key[100], text[1000], map[27];
    int used[26] = {0};
    int i, k = 0, x, choice, ch, lower;

    printf("Enter keyword: ");
    if (scanf("%99s", key) != 1)
        return 1;

    for (i = 0; key[i] != '\0'; i++) {
        char c = (char)toupper((unsigned char)key[i]);

        if (c < 'A' || c > 'Z') {
            printf("Invalid keyword\n");
            return 1;
        }

        if (!used[c - 'A']) {
            used[c - 'A'] = 1;
            map[k++] = c;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!used[i])
            map[k++] = (char)('A' + i);
    }
    map[26] = '\0';

    while ((ch = getchar()) != '\n' && ch != EOF) {}

    printf("Enter text: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

    printf("1. Encrypt  2. Decrypt: ");
    if (scanf("%d", &choice) != 1 ||
        (choice != 1 && choice != 2)) {
        printf("Invalid choice\n");
        return 1;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            lower = islower((unsigned char)text[i]);
            x = toupper((unsigned char)text[i]) - 'A';

            if (choice == 1) {
                text[i] = map[x];
            } else {
                for (k = 0; k < 26; k++)
                    if (map[k] == 'A' + x)
                        break;
                text[i] = (char)('A' + k);
            }

            if (lower)
                text[i] = (char)tolower(
                    (unsigned char)text[i]);
        }
    }

    printf("Result: %s\n", text);
    return 0;
}

