#include <stdio.h>
#include <string.h>

void padText(char* text, int blockSize) {
    int len = strlen(text);
    int pad = blockSize - (len % blockSize);
    if(pad < blockSize) {
        for(int i = 0; i < pad; i++) {
            text[len + i] = 'X';
        }
        text[len + pad] = '\0';
    }
}

void hillEncrypt2x2(char* text, int key[2][2]) {
    for(int i = 0; text[i] != '\0' && text[i + 1] != '\0'; i += 2) {
        int a = text[i] - 'A';
        int b = text[i + 1] - 'A';
        int x = (key[0][0]*a + key[0][1]*b) % 26;
        int y = (key[1][0]*a + key[1][1]*b) % 26;
        text[i] = x + 'A';
        text[i + 1] = y + 'A';
    }
}

void hillEncrypt3x3(char* text, int key[3][3]) {
    for(int i = 0; text[i] != '\0' && text[i + 2] != '\0'; i += 3) {
        int a = text[i] - 'A';
        int b = text[i + 1] - 'A';
        int c = text[i + 2] - 'A';
        int x = (key[0][0]*a + key[0][1]*b + key[0][2]*c) % 26;
        int y = (key[1][0]*a + key[1][1]*b + key[1][2]*c) % 26;
        int z = (key[2][0]*a + key[2][1]*b + key[2][2]*c) % 26;
        text[i] = x + 'A';
        text[i + 1] = y + 'A';
        text[i + 2] = z + 'A';
    }
}

int main() {
    char text[200];
    int choice;

    printf("Enter text to encrypt (uppercase only): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Choose matrix size:\n1. 2x2\n2. 3x3\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        int key[2][2];
        printf("Enter 2x2 key matrix (4 integers):\n");
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                scanf("%d", &key[i][j]);
        padText(text, 2);
        hillEncrypt2x2(text, key);
    } else if(choice == 2) {
        int key[3][3];
        printf("Enter 3x3 key matrix (9 integers):\n");
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                scanf("%d", &key[i][j]);
        padText(text, 3);
        hillEncrypt3x3(text, key);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Encrypted: %s\n", text);
    return 0;
}
