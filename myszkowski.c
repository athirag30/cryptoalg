#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void myszkowskiEncrypt(char* text, int* key, int keyLen, char* result) {
    int len = strlen(text), rows = (len + keyLen - 1) / keyLen, k = 0;
    char grid[rows][keyLen];
    for(int i = 0; i < rows * keyLen; i++) {
        if(i < len) grid[i / keyLen][i % keyLen] = text[i];
        else grid[i / keyLen][i % keyLen] = 'X';
    }
    for(int d = 1; d <= 9; d++) {
        for(int j = 0; j < keyLen; j++) {
            if(key[j] == d) {
                for(int i = 0; i < rows; i++) {
                    result[k++] = grid[i][j];
                }
            }
        }
    }
    result[k] = '\0';
}

int main() {
    char text[100], keyInput[100], result[200];
    int key[50], keyLen;

    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter numeric key (e.g., 3142): ");
    fgets(keyInput, sizeof(keyInput), stdin);
    keyInput[strcspn(keyInput, "\n")] = '\0';

    keyLen = strlen(keyInput);
    for(int i = 0; i < keyLen; i++)
        key[i] = keyInput[i] - '0';

    myszkowskiEncrypt(text, key, keyLen, result);
    printf("Encrypted: %s\n", result);
    return 0;
}
