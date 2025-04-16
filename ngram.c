#include <stdio.h>
#include <string.h>

void ngramEncrypt(char* text) {
    for(int i = 0; text[i] != '\0'; i += 2) {
        if(text[i + 1] == '\0') break;
        char temp = text[i];
        text[i] = text[i + 1];
        text[i + 1] = temp;
    }
}

int main() {
    char text[100];
    printf("Enter text to encrypt (even length): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    ngramEncrypt(text);
    printf("Encrypted: %s\n", text);
    return 0;
}
