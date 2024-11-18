#include <stdio.h>
#include <string.h>
#include <ctype.h>
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; 
}
void affineEncrypt(char text[], int a, int b) {
    int n = strlen(text);
    for (int i = 0; i < n; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = ((a * (text[i] - base) + b) % 26) + base;
        }
    }
}
void affineDecrypt(char text[], int a, int b) {
    int n = strlen(text);
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        printf("No inverse exists for the value of a\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = ((a_inv * ((text[i] - base - b + 26) % 26)) % 26) + base;
        }
    }
}
int main() {
    char text[100];
    int a, b, choice;
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    printf("Enter values for a and b (a must be coprime with 26): ");
    scanf("%d %d", &a, &b);
    printf("Choose an option:\n1. Encrypt\n2. Decrypt\nEnter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        affineEncrypt(text, a, b);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        affineDecrypt(text, a, b);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
