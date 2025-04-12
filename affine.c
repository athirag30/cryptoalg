#include <stdio.h>
char affineEncryptChar(char ch, int a, int b) {
    if(ch >= 'A' && ch <= 'Z')
        return ((a * (ch - 'A') + b) % 26) + 'A';
    return ch;
}
int main() {
    char text[] = "HELLO";
    int a = 5, b = 8;
    for(int i = 0; text[i] != '\0'; i++)
        text[i] = affineEncryptChar(text[i], a, b);
    printf("Encrypted: %s\n", text);
    return 0;
}