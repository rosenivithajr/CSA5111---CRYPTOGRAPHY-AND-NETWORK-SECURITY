
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[5000], result[5000];
    char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int freq[26], order[26];
    int i, j, temp, x, top;

    for (i = 0; i < 26; i++) {
        freq[i] = 0;
        order[i] = i;
    }

    printf("Enter ciphertext: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

    printf("Number of candidates (1-10): ");
    if (scanf("%d", &top) != 1 || top < 1 || top > 10) {
        printf("Invalid number\n");
        return 1;
    }

    for (i = 0; text[i] != '\0'; i++)
        if (isalpha((unsigned char)text[i]))
            freq[toupper((unsigned char)text[i]) - 'A']++;

    for (i = 0; i < 25; i++) {
        for (j = i + 1; j < 26; j++) {
            if (freq[order[j]] > freq[order[i]]) {
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            x = toupper((unsigned char)text[i]) - 'A';

            for (j = 0; j < 26; j++)
                if (order[j] == x)
                    break;

            result[i] = english[j];

            if (islower((unsigned char)text[i]))
                result[i] = (char)tolower(
                    (unsigned char)result[i]);
        } else {
            result[i] = text[i];
        }
    }

    result[i] = '\0';

    printf("Frequency-based candidate: %s\n", result);
    printf("Note: this method estimates one candidate only.\n");

    return 0;
}

