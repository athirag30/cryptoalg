#include <stdio.h>
#include <string.h>

void autoclaveEncrypt(char* text, char* key) {
    int i;
    char fullKey[200];
    strcpy(fullKey, key);
    strcat(fullKey, text);
    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + (fullKey[i] - 'A')) % 26) + 'A';
        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((text[i] - 'a' + (fullKey[i] - 'a')) % 26) + 'a';
    }
}

int main() {
    char text[100], key[100];
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter initial key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    autoclaveEncrypt(text, key);
    printf("Encrypted: %s\n", text);
    return 0;
}
