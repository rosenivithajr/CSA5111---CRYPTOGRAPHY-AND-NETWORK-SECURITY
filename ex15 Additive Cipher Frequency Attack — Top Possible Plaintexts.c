
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10000

double english[26] = {
    8.167, 1.492, 2.782, 4.253, 12.702, 2.228,
    2.015, 6.094, 6.966, 0.153, 0.772, 4.025,
    2.406, 6.749, 7.507, 1.929, 0.095, 5.987,
    6.327, 9.056, 2.758, 0.978, 2.360, 0.150,
    1.974, 0.074
};

int main()
{
    char text[MAX], result[26][MAX];
    int freq[26], shift, i, x, n = 0, top;
    int order[26], j, temp;
    double score[26], expected, diff;

    printf("Enter ciphertext: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

    for (i = 0; text[i] != '\0'; i++)
        if (isalpha((unsigned char)text[i]))
            n++;

    if (n == 0) {
        printf("No letters found\n");
        return 1;
    }

    printf("Number of candidates (1-10): ");
    if (scanf("%d", &top) != 1 || top < 1 || top > 10) {
        printf("Invalid number\n");
        return 1;
    }

    for (shift = 0; shift < 26; shift++) {
        for (i = 0; i < 26; i++)
            freq[i] = 0;

        for (i = 0; text[i] != '\0'; i++) {
            if (isalpha((unsigned char)text[i])) {
                x = toupper((unsigned char)text[i]) - 'A';
                x = (x - shift + 26) % 26;
                freq[x]++;
            }
        }

        score[shift] = 0.0;

        for (i = 0; i < 26; i++) {
            expected = n * english[i] / 100.0;

            if (expected > 0.0) {
                diff = freq[i] - expected;
                score[shift] += diff * diff / expected;
            }
        }

        for (i = 0; text[i] != '\0'; i++) {
            if (isalpha((unsigned char)text[i])) {
                int base = isupper((unsigned char)text[i])
                           ? 'A' : 'a';
                x = toupper((unsigned char)text[i]) - 'A';
                result[shift][i] =
                    (char)(base + (x - shift + 26) % 26);
            } else {
                result[shift][i] = text[i];
            }
        }
        result[shift][i] = '\0';
        order[shift] = shift;
    }

    for (i = 0; i < 25; i++) {
        for (j = i + 1; j < 26; j++) {
            if (score[order[j]] < score[order[i]]) {
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    printf("\nTop %d candidates:\n", top);

    for (i = 0; i < top; i++) {
        shift = order[i];
        printf("%d. Shift %d: %s\n",
               i + 1, shift, result[shift]);
    }

    return 0;
}

