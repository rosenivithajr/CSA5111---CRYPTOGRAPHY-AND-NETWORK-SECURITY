
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char text[1000], key[27];
    int seen[26] = {0};
    int i, j, choice, x, upper, ch;

    printf("Enter 26-letter key: ");
    if (scanf("%26s", key) != 1)
        return 1;

    if (strlen(key) != 26) {
        printf("Invalid key length\n");
        return 1;
    }

    /* Validate the substitution key */
    for (i = 0; i < 26; i++) {
        key[i] = (char)toupper((unsigned char)key[i]);

        if (key[i] < 'A' || key[i] > 'Z' ||
            seen[key[i] - 'A'] == 1) {
            printf("Invalid key: use each letter once\n");
            return 1;
        }

        seen[key[i] - 'A'] = 1;
    }

    /* Clear the input buffer */
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }

    printf("Enter text: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

    text[strcspn(text, "\n")] = '\0';

    printf("1. Encrypt  2. Decrypt\n");
    printf("Choice: ");

    if (scanf("%d", &choice) != 1 ||
        (choice != 1 && choice != 2)) {
        printf("Invalid choice\n");
        return 1;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            upper = isupper((unsigned char)text[i]);
            x = toupper((unsigned char)text[i]) - 'A';

            if (choice == 1) {
                text[i] = key[x];
            } else {
                for (j = 0; j < 26; j++) {
                    if (key[j] == (char)('A' + x))
                        break;
                }

                text[i] = (char)('A' + j);
            }

            if (!upper) {
                text[i] =
                    (char)tolower((unsigned char)text[i]);
            }
        }
    }

    printf("Result: %s\n", text);

    return 0;
}

