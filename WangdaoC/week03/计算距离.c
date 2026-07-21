#include <stdio.h>
#include <math.h>

// 1️⃣ 计算两点间距离的自定义函数
double distance(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;  // x方向差值
    int dy = y2 - y1;  // y方向差值
    return sqrt(dx * dx + dy * dy);  // 欧几里得距离公式
}

int main() {
    int n;
    scanf("%d", &n);  // 2️⃣ 读取点的数量
    
    int x[10], y[10];  // 3️⃣ 存储点的坐标（最多10个点）
    
    // 4️⃣ 读取n个点的坐标
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    
    double totalDistance = 0.0;  // 5️⃣ 总距离初始化为0
    
    // 6️⃣ 计算相邻点之间的折线距离并累加
    for (int i = 0; i < n - 1; i++) {
        totalDistance += distance(x[i], y[i], x[i + 1], y[i + 1]);
    }
    
    // 7️⃣ 输出结果，保留两位小数
    printf("%.2f\n", totalDistance);
    
    return 0;
}