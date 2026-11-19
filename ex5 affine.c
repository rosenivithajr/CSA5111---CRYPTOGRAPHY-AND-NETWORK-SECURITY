
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b)
{
    int t;

    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int inverse(int a)
{
    int i;

    for (i = 1; i < 26; i++)
        if ((a * i) % 26 == 1)
            return i;

    return -1;
}

int main()
{
    char text[500];
    int a, b, choice, i, x, y, base, inv;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    a = (a % 26 + 26) % 26;
    b = (b % 26 + 26) % 26;

    if (gcd(a, 26) != 1) {
        printf("Invalid a value\n");
        return 1;
    }

    printf("1. Encrypt  2. Decrypt: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice\n");
        return 1;
    }

    inv = inverse(a);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            x = toupper((unsigned char)text[i]) - 'A';

            if (choice == 1)
                y = (a * x + b) % 26;
            else
                y = (inv * (x - b + 26)) % 26;

            text[i] = (char)(base + y);
        }
    }

    printf("Result: %s\n", text);
    return 0;
}

