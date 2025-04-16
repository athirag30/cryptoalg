#include <stdio.h>
#include <string.h>

void vigenereEncrypt(char* text, char* key) {
    int keyLen = strlen(key), j = 0;
    for(int i = 0; text[i] != '\0'; i++) {
        char k = key[j % keyLen];
        if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + (k - 'A')) % 26) + 'A';
            j++;
        } else if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + (k - 'a')) % 26) + 'a';
            j++;
        }
    }
}

int main() {
    char text[100], key[100];
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    vigenereEncrypt(text, key);
    printf("Encrypted: %s\n", text);
    return 0;
}
