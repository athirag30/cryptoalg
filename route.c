#include <stdio.h>
#include <string.h>
void routeEncrypt(char* text, int rows, int cols) {
    char grid[rows][cols];
    int k = 0;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            grid[i][j] = text[k++];
    for(int j = 0; j < cols; j++)
        for(int i = 0; i < rows; i++)
            printf("%c", grid[i][j]);
    printf("\n");
}
int main() {
    char text[] = "HELLOWORLD";
    routeEncrypt(text, 2, 5);
    return 0;
}