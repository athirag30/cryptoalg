#include <stdio.h>
#include <string.h>
void myszkowskiEncrypt(char* text, char* key) {
    int len = strlen(text);
    int key_len = strlen(key);
    int i, j;
    for(char ch = '1'; ch <= '9'; ch++) {
        for(i = 0; i < key_len; i++) {
            if(key[i] == ch) {
                for(j = i; j < len; j += key_len)
                    printf("%c", text[j]);
            }
        }
    }
    printf("\n");
}
int main() {
    char text[] = "WEAREDISCOVEREDFLEEATONCE";
    char key[] = "31233";
    myszkowskiEncrypt(text, key);
    return 0;
}