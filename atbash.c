#include <stdio.h>
#include <string.h>

void atbashEncrypt(char* text) {
    for(int i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = 'Z' - (text[i] - 'A');
        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = 'z' - (text[i] - 'a');
    }
}

int main() {
    char text[100];
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    atbashEncrypt(text);
    printf("Encrypted: %s\n", text);
    return 0;
}
