#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char* text, int rails) {
    int len = strlen(text);
    char rail[rails][len];
    for(int i = 0; i < rails; i++)
        for(int j = 0; j < len; j++)
            rail[i][j] = '\n';
    int dir_down = 0, row = 0, col = 0;
    for(int i = 0; i < len; i++) {
        if(row == 0 || row == rails - 1)
            dir_down = !dir_down;
        rail[row][col++] = text[i];
        dir_down ? row++ : row--;
    }
    for(int i = 0; i < rails; i++)
        for(int j = 0; j < len; j++)
            if(rail[i][j] != '\n')
                printf("%c", rail[i][j]);
    printf("\n");
}
int main() {
    char text[] = "HELLO";
    int rails = 2;
    railFenceEncrypt(text, rails);
    return 0;
}