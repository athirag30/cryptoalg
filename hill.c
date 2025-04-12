#include <stdio.h>
#define SIZE 2
void hillEncrypt(int key[SIZE][SIZE], char* msg) {
    int msgVec[SIZE];
    int resVec[SIZE];
    for(int i = 0; i < SIZE; i++)
        msgVec[i] = msg[i] - 'A';
    for(int i = 0; i < SIZE; i++) {
        resVec[i] = 0;
        for(int j = 0; j < SIZE; j++) {
            resVec[i] += key[i][j] * msgVec[j];
        }
        resVec[i] %= 26;
    }
    printf("Encrypted: ");
    for(int i = 0; i < SIZE; i++)
        printf("%c", resVec[i] + 'A');
    printf("\n");
}
int main() {
    int key[2][2] = {{3, 3}, {2, 5}};
    char msg[] = "HI";
    hillEncrypt(key, msg);
    return 0;
}