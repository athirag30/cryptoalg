#include <stdio.h>
#include <string.h>
void vigenereEncrypt(char* text, char* key) {
    int n = strlen(text), m = strlen(key);
    for(int i = 0; i < n; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + (key[i % m] - 'A')) % 26) + 'A';
    }
}
int main() {
    char text[] = "HELLO";
    char key[] = "KEY";
    vigenereEncrypt(text, key);
    printf("Encrypted: %s\n", text);
    return 0;
}