#include <stdio.h>
#include <string.h>

char affineEncryptChar(char ch, int a, int b) {
    if(ch >= 'A' && ch <= 'Z')
        return ((a * (ch - 'A') + b) % 26) + 'A';
    else if(ch >= 'a' && ch <= 'z')
        return ((a * (ch - 'a') + b) % 26) + 'a';
    return ch;
}

int main() {
    char text[100];
    int a = 5, b = 8;

    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    for(int i = 0; text[i] != '\0'; i++) {
        text[i] = affineEncryptChar(text[i], a, b);
    }

    printf("Encrypted: %s\n", text);
    return 0;
}
