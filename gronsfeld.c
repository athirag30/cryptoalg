#include <stdio.h>
#include <string.h>

void gronsfeldEncrypt(char* text, char* key) {
    int keyLen = strlen(key), j = 0;
    for(int i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            int shift = key[j % keyLen] - '0';
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
            j++;
        } else if(text[i] >= 'a' && text[i] <= 'z') {
            int shift = key[j % keyLen] - '0';
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
            j++;
        }
    }
}

int main() {
    char text[100], key[100];
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter numeric key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    gronsfeldEncrypt(text, key);
    printf("Encrypted: %s\n", text);
    return 0;
}
