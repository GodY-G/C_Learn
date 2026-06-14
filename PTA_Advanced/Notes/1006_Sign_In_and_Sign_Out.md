# PAT 1006 — Sign In and Sign Out

https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7

---

## 题目

给 M 个员工，每人一条记录：ID号 + 上班签到时间 + 下班签出时间。找**最早到**的人和**最晚走**的人。

```
输入：
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

输出：
SC3021234 CS301133
   ↑          ↑
 最早来     最晚走
```

---

## 思路

时间格式 `HH:MM:SS` 固定 8 位，**直接当字符串比大小**。`"08:00:00" < "15:30:28"` 字符逐位比较，位数固定所以等价于时间先后。

- 最早来 = 签入时间字符串**最小**
- 最晚走 = 签出时间字符串**最大**

---

## C 代码

```c
#include <stdio.h>
#include <string.h>

int main() {
    int m;
    scanf("%d", &m);

    char id_in[16], id_out[16];       // 最早/最晚的人ID
    char time_in[10], time_out[10];   // 最早签入时间 / 最晚签出时间
    char id[16], in[10], out[10];     // 当前读入的临时变量

    // 读第一条，初始化
    scanf("%s %s %s", id, in, out);
    strcpy(id_in, id);
    strcpy(id_out, id);
    strcpy(time_in, in);
    strcpy(time_out, out);

    // 读剩下的 M-1 条
    for (int i = 1; i < m; i++) {
        scanf("%s %s %s", id, in, out);

        // 签入更早 → 更新最早记录
        if (strcmp(in, time_in) < 0) {
            strcpy(id_in, id);
            strcpy(time_in, in);
        }

        // 签出更晚 → 更新最晚记录
        if (strcmp(out, time_out) > 0) {
            strcpy(id_out, id);
            strcpy(time_out, out);
        }
    }

    printf("%s %s", id_in, id_out);
    return 0;
}
```

---

## 逐行解析

### 1. 为什么字符串比较等价于时间比较？

```
"08:00:00" vs "15:30:28"
逐位：'0' < '1' → 更早 ✓

"21:45:00" vs "21:58:40"
前三位 "21:" 相同，第五位 '4' < '5' → 45分 < 58分 → 更早 ✓
```

位数固定 8 位 `HH:MM:SS`，字符集小且逐位比较 = 时间先后。不需要拆成时分秒。

### 2. strcmp 返回值

```c
strcmp(a, b)：
  < 0  →  a 更小（更早）
  = 0  →  相等
  > 0  →  a 更大（更晚）
```

### 3. 更新逻辑

```c
if (strcmp(in, time_in) < 0)     // 当前签入比"已知最早"还早
    → 更新最早记录

if (strcmp(out, time_out) > 0)   // 当前签出比"已知最晚"还晚
    → 更新最晚记录
```

### 4. 先读第一条初始化

```c
scanf("%s %s %s", id, in, out);   // 第一条记录
strcpy(id_in, id);                 // 初始化为当前最早/最晚
strcpy(time_in, in);
```

不初始化的话 `time_in` 是垃圾值，`strcmp` 会崩溃。

---

## 手算示例

```
输入：
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

初始化（i=0，第一条）：
  id_in = "CS301111", time_in = "15:30:28"
  id_out = "CS301111", time_out = "17:00:10"

i=1（第二条）：
  in="08:00:00" < time_in="15:30:28" → 更新最早
  id_in = "SC3021234", time_in = "08:00:00"
  out="11:25:25" < time_out="17:00:10" → 不更新

i=2（第三条）：
  in="21:45:00" > time_in="08:00:00" → 不更新
  out="21:58:40" > time_out="17:00:10" → 更新最晚
  id_out = "CS301133", time_out = "21:58:40"

输出：SC3021234 CS301133 ✓
```

---

## 易错点

| 坑 | 说明 |
|------|------|
| 没初始化 | `strcmp(in, time_in)` 而 `time_in` 未赋值 → 段错误 |
| 比较符号反了 | 最早 = 时间最小(`<`)；最晚 = 时间最大(`>`) |
| strcmp 返回值弄反 | `strcmp(a,b) < 0` 表示 a 小，不是 b 小 |
| 数组开太小 | ID 最长 15 字符，开 16（+`\0`）；时间 8 字符，开 10 |
