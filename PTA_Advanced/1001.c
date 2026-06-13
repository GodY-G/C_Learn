#include <stdio.h>
#include <stdlib.h>   // abs

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int sum = a + b;

    if (sum < 0) {
        printf("-");
        sum = -sum;
    }

    // 把每三位存进数组
    int parts[10], cnt = 0;
    if (sum == 0) {
        printf("0");
        return 0;
    }

    while (sum > 0) {
        parts[cnt++] = sum % 1000;
        sum /= 1000;
    }

    // 倒序输出（cnt-1 是最高位）
    printf("%d", parts[cnt - 1]);               // 最高位不加前导零
    for (int i = cnt - 2; i >= 0; i--) {
        printf(",%03d", parts[i]);              // 后面每组补零到 3 位
    }

    return 0;
}