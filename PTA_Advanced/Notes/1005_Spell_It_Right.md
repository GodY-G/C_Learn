# PAT 1005 — Spell It Right（数字各位求和转英文）

https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7

---

## 题目

给定 N（≤ 10^100），求每位数字之和，把和的每一位用英文单词输出，空格分隔。

```
输入：12345
输出：one five

输入：0
输出：zero
```

---

## 思路

1. N 最大 10^100，**int 装不下** → 用字符串 `char[105]` 读入
2. 字符转数字累加：`n[i] - '0'` → sum
3. sum=0 特判：输出 `zero`
4. sum 的每位拆出来存数组
5. 倒序输出英文单词 + 空格

---

## C 代码

```c
#include <stdio.h>

int main() {
    char n[105];
    scanf("%s", n);

    // 1. 字符转数字，逐位求和
    int sum = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        sum += n[i] - '0';
    }

    const char *s[10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };

    // 2. sum=0 特判
    if (sum == 0) {
        printf("zero");
        return 0;
    }

    // 3. 拆 sum 的每一位
    int digits[10], cnt = 0;
    while (sum) {
        digits[cnt++] = sum % 10;
        sum /= 10;
    }

    // 4. 倒序输出（高位→低位）
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%s", s[digits[i]]);
        if (i > 0) printf(" ");
    }

    return 0;
}
```

---

## 逐行解析

### 1. 为什么用字符串读入？

```c
char n[105];
scanf("%s", n);
```

N ≤ 10^100，即最多 100 位数字。C 语言中 `int` 最大约 2×10⁹（10 位），`long long` 最大约 9×10¹⁸（19 位），都远不够 100 位。必须用字符串。

### 2. 字符转数字

```c
sum += n[i] - '0';
```

字符 `'3'` 的 ASCII 码是 51。`'3' - '0'` = 51 - 48 = 3。这是 C 语言字符转数字的标准写法。

```
输入 "12345"：
  i=0: '1' → 1, sum=1
  i=1: '2' → 2, sum=3
  i=2: '3' → 3, sum=6
  i=3: '4' → 4, sum=10
  i=4: '5' → 5, sum=15
```

### 3. sum=0 特判

```c
if (sum == 0) {
    printf("zero");
    return 0;
}
```

输入 `"0"` → sum=0 → while 循环一次不进 → digits 数组为空 → 什么都不输出。所以必须特判。

### 4. 拆位存数组

```c
int digits[10], cnt = 0;
while (sum) {
    digits[cnt++] = sum % 10;
    sum /= 10;
}
```

```
sum = 15：
  第一次：digits[0] = 15%10 = 5, cnt=1, sum=1
  第二次：digits[1] = 1%10  = 1, cnt=2, sum=0

digits = [5, 1], cnt=2
```

注意：存的是**低位在前**（个位在 [0]，高位在 [cnt-1]）。

### 5. 倒序输出 + 空格

```c
for (int i = cnt - 1; i >= 0; i--) {
    printf("%s", s[digits[i]]);
    if (i > 0) printf(" ");
}
```

```
digits = [5, 1]：
  i=1: s[1]="one" → 打印 "one" → i>0 → 空格
  i=0: s[5]="five" → 打印 "five" → i=0 → 不加空格

输出：one five ✓
```

### 6. 字符串内存布局

```
输入 "12345"：
  下标: [0]='1' [1]='2' [2]='3' [3]='4' [4]='5' [5]='\0' [6]~[104]=未使用

遍历条件 n[i] != '\0' → 到 [5] 停止
`\0` 是 scanf 自动加在末尾的字符串结束符（ASCII=0）
```

---

## 常见错误

| 错误写法 | 问题 | 正确写法 |
|------|------|------|
| `scanf("%d", &n)` | int 装不下 10^100 | `scanf("%s", n)` |
| 从低位开始输出 | 输出 `five one` 而非 `one five` | 存入数组再倒序输出 |
| 忘了 sum=0 特判 | 输入 "0" 什么都不输出 | 加 `if(sum==0)` |
| 没加空格 | 输出 `onefive` | 每项后 `if(i>0) printf(" ")` |
| 用 `int n` 存字符串 | 类型错误 | `char n[105]` |

---

## 数据流

```
输入 "12345"
  │
  ▼
n = ['1','2','3','4','5','\0', ...]
  │  n[i] - '0'
  ▼
sum = 15
  │  sum%10 / sum/10
  ▼
digits = [5, 1], cnt=2
  │  倒序
  ▼
"one five"
```
