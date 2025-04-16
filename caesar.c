#include <stdio.h>
#include <string.h>

void caesarEncrypt(char* text, int shift) {
    for(int i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
    }
}

int main() {
    char text[100];
    int shift = 3;
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    caesarEncrypt(text, shift);
    printf("Encrypted: %s\n", text);
    return 0;
}
