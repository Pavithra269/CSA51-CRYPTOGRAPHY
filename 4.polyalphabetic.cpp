#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereCipher(char text[], char key[], int isEncrypt) {
    int textLen = strlen(text), keyLen = strlen(key), j = 0;
    for (int i = 0; i < textLen; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char offset = islower(c) ? 'a' : 'A';
            char keyChar = tolower(key[j % keyLen]) - 'a';
            if (!isEncrypt) keyChar = -keyChar; 
            text[i] = (c - offset + keyChar + 26) % 26 + offset;
            j++;
        }
    }
}
int main() {
    char text[100], key[100];
    int choice;
    printf("Enter the key: ");
    scanf("%s", key);
    printf("Enter the text: ");
    getchar(); 
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Choose an option:\n1. Encrypt\n2. Decrypt\nEnter your choice: ");
    scanf("%d", &choice);
    if (choice == 1 || choice == 2) {
        vigenereCipher(text, key, choice == 1);
        printf("Result: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
