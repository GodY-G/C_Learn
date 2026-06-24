#include <stdio.h>

int main() {
    char radix[] = "0123456789ABC";
    int c[3];
    scanf("%d %d %d", &c[0], &c[1], &c[2]);

    printf("#");
    for (int i = 0; i < 3; i++) {
        printf("%c%c", radix[c[i] / 13], radix[c[i] % 13]);
    }
    return 0;
}