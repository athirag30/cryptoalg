#include <stdio.h>
#include <string.h>

void railFenceEncrypt(char* text, char* result) {
    int len = strlen(text), k = 0;
    for(int i = 0; i < len; i += 2)
        result[k++] = text[i];
    for(int i = 1; i < len; i += 2)
        result[k++] = text[i];
    result[k] = '\0';
}

int main() {
    char text[100], result[100];
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    railFenceEncrypt(text, result);
    printf("Encrypted: %s\n", result);
    return 0;
}
