#include <stdio.h>
#include <string.h>
void beaufortEncrypt(char* text, char* key) {
    int n = strlen(text), m = strlen(key);
    for(int i = 0; i < n; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((key[i % m] - text[i] + 26) % 26) + 'A';
    }
}
int main() {
    char text[] = "HELLO";
    char key[] = "KEY";
    beaufortEncrypt(text, key);
    printf("Encrypted: %s\n", text);
    return 0;
}