#include <stdio.h>
#include <string.h>
void ngram(char* text, int n) {
    int len = strlen(text);
    for(int i = 0; i <= len - n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", text[i + j]);
        }
        printf("\n");
    }
}
int main() {
    char text[] = "HELLOWORLD";
    int n = 3;
    ngram(text, n);
    return 0;
}