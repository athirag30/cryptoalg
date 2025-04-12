#include <stdio.h>
#include <string.h>
void augustEncrypt(char* text) {
    for(int i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + 1) % 26) + 'A';
        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((text[i] - 'a' + 1) % 26) + 'a';
    }
}
int main() {
    char text[] = "HELLO";
    augustEncrypt(text);
    printf("Encrypted: %s\n", text);
    return 0;
}
