#include <stdio.h>
#include <string.h>

void beaufortEncrypt(char* text, char* key) {
    int keyLen = strlen(key), j = 0;
    for(int i = 0; text[i] != '\0'; i++) {
        char k = key[j % keyLen];
        if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((26 + (k - 'A') - (text[i] - 'A')) % 26) + 'A';
            j++;
        } else if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((26 + (k - 'a') - (text[i] - 'a')) % 26) + 'a';
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
    beaufortEncrypt(text, key);
    printf("Encrypted: %s\n", text);
    return 0;
}
