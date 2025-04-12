#include <stdio.h>
#include <string.h>
void autokeyEncrypt(char* text, char* key) {
    int n = strlen(text);
    char new_key[100];
    strcpy(new_key, key);
    strncat(new_key, text, n - strlen(key));
    for(int i = 0; i < n; i++) {
        text[i] = ((text[i] - 'A' + new_key[i] - 'A') % 26) + 'A';
    }
}
int main() {
    char text[] = "HELLO";
    char key[] = "K";
    autokeyEncrypt(text, key);
    printf("Encrypted: %s\n", text);
    return 0;
}