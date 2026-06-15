# PAT 1008 — Elevator（电梯）

https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7

---

## 题目

电梯从 **0 楼**出发，按顺序到达请求楼层。上楼 6 秒/层，下楼 4 秒/层，停一次 5 秒。求总时间。

```
输入：3 2 3 1
输出：41
```

---

## 思路

记 `cur` = 当前楼层（初始 0）。每读一个新楼层 `next`：
- `next > cur` → 上楼 → (next-cur)×6
- `next < cur` → 下楼 → (cur-next)×4
- `next == cur` → 同层 → 0
- 每楼必停 → +5

---

## C 代码

```c
#include <stdio.h>

int main() {
    int n, cur = 0, total = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int next, diff;
        scanf("%d", &next);
        diff = next - cur;

        if (diff > 0)
            total += 6 * diff;
        else
            total += -4 * diff;   // diff ≤ 0 → -diff = |diff|

        total += 5;               // 停的 5 秒不管 diff 同不同都要加
        cur = next;
    }

    printf("%d", total);
    return 0;
}
```

---

## 手算

```
cur=0, total=0

next=2: 2>0 → 2×6=12, +5 → cur=2, total=17
next=3: 3>2 → 1×6=6,  +5 → cur=3, total=28
next=1: 1<3 → 2×4=8,  +5 → cur=1, total=41

输出：41
```

---

## 易错点

| 坑 | 说明 |
|------|------|
| cur 在循环外初始化 | `cur` 必须在循环外声明并初始为 0，不能每次循环重置 |
| diff=0 时也要加 5 | 同楼层题目没说不可能，停的 5 秒必须统一加，不能写在 if(diff>0) 和 if(diff<0) 里面 |
| 下楼梯公式 | `(cur-next)×4`，用 `-diff×4` 或者 `-4*diff`（因为 diff<0 时 -diff = |diff|） |
| 初始楼层 0 | 不是 1 |
| `%d` 输出 | 总时间是整数，直接 `%d` |
