#include <stdio.h>
#include <string.h>
void gronsfeldEncrypt(char* text, int* key, int key_len) {
    for(int i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + key[i % key_len]) % 26) + 'A';
    }
}
int main() {
    char text[] = "HELLO";
    int key[] = {1, 2, 3};
    gronsfeldEncrypt(text, key, 3);
    printf("Encrypted: %s\n", text);
    return 0;
}