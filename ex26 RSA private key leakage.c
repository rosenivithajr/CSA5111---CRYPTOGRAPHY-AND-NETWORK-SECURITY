
#include <stdio.h>

int main()
{
    printf("RSA Private Key Leakage\n");
    printf("-----------------------\n");
    printf("Bob's modulus n is unchanged.\n");
    printf("His old private key d has been leaked.\n");
    printf("Generating a new public and private exponent\n");
    printf("with the same modulus is not safe.\n");
    printf("An attacker may recover the factors of n\n");
    printf("using the leaked RSA key information.\n");
    printf("Bob should generate a completely new RSA key pair.\n");

    return 0;
}

