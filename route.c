#include <stdio.h>
#include <string.h>

void routeEncrypt(char* text, char* result) {
    int len = strlen(text), size = 4, k = 0;
    char grid[4][4];
    for(int i = 0; i < size * size; i++) {
        if(i < len) grid[i / size][i % size] = text[i];
        else grid[i / size][i % size] = 'X';
    }
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            result[k++] = grid[i][j];
    result[k] = '\0';
}

int main() {
    char text[100], result[100];
    printf("Enter text to encrypt (max 16 chars): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    routeEncrypt(text, result);
    printf("Encrypted: %s\n", result);
    return 0;
}
