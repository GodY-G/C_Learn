## C 语言字符串操作完整总结

### 零、核心概念：C 的字符串就是字符数组

```c
char s[6] = {'h','e','l','l','o','\0'};  // 本质：字符数组
char s[6] = "hello";                      // 等价写法
//  s[0]='h'  s[1]='e'  s[2]='l'  s[3]='l'  s[4]='o'  s[5]='\0'
```

特点是最后必须有一个隐藏的 `'\0'`（ASCII 码 0），表示"字符串结束"。数组大小 = 可见字符数 + 1（留给 `'\0'`）。

---

### 一、输入/输出

| 函数 | 用法 | 何时结束 | 加 `\0` | 读不读空格 |
|------|------|---------|:---:|:---:|
| `scanf("%s", s)` | 读一个单词 | 遇到空格/换行 | 自动加 | 不读 |
| `scanf("%10s", s)` | 读最多 10 个字符 | 同上 | 自动加 | 不读 |
| `gets(s)` | **已废弃，不要用** | 换行 | 自动加 | 读 |
| `fgets(s, n, stdin)` | **推荐**，读最多 n-1 个 | 换行 或 达到 n-1 | 自动加 | 读 |
| `ch = getchar()` | 读一个字符 | — | — | 读一切 |
| `printf("%s", s)` | 输出字符串 | 遇到 `\0` | — | — |
| `puts(s)` | 输出字符串 + 自动换行 | 同上 | — | — |

```c
// fgets 的坑：会保留换行符
char s[100];
fgets(s, 100, stdin);   // 输入 "hello" + 回车 → s = "hello\n\0"
s[strcspn(s, "\n")] = '\0';  // 去掉末尾的 '\n'
```

```c
// scanf 的坑：残留换行符
scanf("%d", &n);        // 输入 "3\n"，scanf 读了 3，\n 还在缓冲区
getchar();              // 吃掉那个 \n，否则下次 scanf("%s") 会读到空串
```

---

### 二、`<string.h>` 常用函数

#### 2.1 长度

```c
#include <string.h>

char s[] = "hello";
int len = strlen(s);        // len = 5（不计算 '\0'）
// 注意：strlen 遇到 '\0' 就停，返回的是可见字符数
```

#### 2.2 拷贝

```c
strcpy(dest, src);       // 把 src 拷贝到 dest（危险：不检查越界）
strncpy(dest, src, n);   // 最多拷贝 n 个字符（安全）
```

```c
char a[20];
strcpy(a, "hello");      // a = "hello\0"  （常用）

// strncpy 的坑：如果 src 长度 < n，会填充很多 \0
char b[20];
strncpy(b, "hi", 5);     // b = "hi\0\0\0\0\0..."
```

#### 2.3 比较

```c
strcmp(s1, s2);          // 比较两个字符串
// 返回值：0 = 相等，负数 = s1 < s2，正数 = s1 > s2

if (strcmp(a, b) == 0) {
    printf("相同\n");
}

// 注意：不能直接用 == 比较！
if (a == b)  { ... }     // ★ 错的！这比的是数组地址，不是内容
```

#### 2.4 连接

```c
strcat(dest, src);       // 把 src 接到 dest 末尾
strncat(dest, src, n);   // 最多接 n 个字符
```

```c
char s[30] = "hello";
strcat(s, " world");     // s = "hello world\0"
// 危险：dest 必须足够大，否则越界
```

#### 2.5 查找

```c
strchr(s, ch);           // 在 s 中找字符 ch，返回位置指针
strstr(s, sub);          // 在 s 中找子串 sub
strcspn(s, chars);       // 返回 s 开头连续不包含 chars 中任何字符的长度
```

```c
char *p = strchr("hello", 'e');   // p 指向 'e'

// strcspn 的常见用法：去掉 fgets 留下的 \n
s[strcspn(s, "\n")] = '\0';    // 找到 \n 的位置，替换为 \0
/*
   strcspn("abc\n", "\n")  → 返回 3（'\n' 在位置 3）
   s[3] = '\0' → 把 '\n' 切掉
*/
```

---

### 三、`<ctype.h>` 字符判断函数

```c
#include <ctype.h>

isalpha(ch)     // 是否是字母 (a-z, A-Z)
isdigit(ch)     // 是否是数字 (0-9)
isalnum(ch)     // 是否是字母或数字
isspace(ch)     // 是否是空白（空格、\t、\n 等）
islower(ch)     // 是否是小写字母
isupper(ch)     // 是否是大写字母
tolower(ch)     // 转小写
toupper(ch)     // 转大写
```

---

### 四、`<stdlib.h>` 转换函数

```c
#include <stdlib.h>

atoi("123")     // 字符串 → int，返回 123
atof("3.14")    // 字符串 → double，返回 3.14
```

---

### 五、逐个字符遍历

```c
// 逐个字符访问（三种写法）

// 方式 1：用索引
for (int i = 0; s[i] != '\0'; i++) {
    printf("%c", s[i]);          // s[i] 就是第 i 个字符
}

// 方式 2：用指针
char *p = s;
while (*p != '\0') {
    printf("%c", *p);            // *p 就是当前字符
    p++;                         // p 移到下一个字符
}

// 方式 3：while 条件中读（PAT 常用）
int i = 0;
char ch;
while (i < 10 && (ch = getchar()) != '\n') {
    s[i++] = ch;
}
s[i] = '\0';                     // ★ 必须手动补结束符
```

---

### 六、常用操作速查

```c
// 获取字符串长度
int len = strlen(s);

// 拷贝字符串
strcpy(dest, src);

// 判断两个字符串是否相等
if (strcmp(a, b) == 0)

// 判断是否是空字符串
if (strlen(s) == 0)         // 或 if (s[0] == '\0')

// 清空字符串
s[0] = '\0';                // 不需要挨个清，设第一个为 \0 就够了

// 取最后一个字符
char last = s[strlen(s) - 1];

// 反转字符串（双指针）
int left = 0, right = strlen(s) - 1;
while (left < right) {
    char tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
    left++; right--;
}
```

---

### 七、最常见的坑

| 坑 | 说明 |
|----|------|
| 数组大小不够 | `char s[5] = "hello"` 会越界，需要 `char s[6]`（给 `\0` 留位置） |
| `scanf("%d")` 后残留 `\n` | 用 `getchar()` 吃掉 |
| `fgets` 会保留 `\n` | 用 `s[strcspn(s, "\n")] = '\0'` 去掉 |
| `==` 比较字符串 | 必须用 `strcmp`，不能用 `==` |
| `scanf("%s")` 读到空格就停 | 需要读空格用 `fgets` |
| `strlen` 不算 `\0` | 数组大小必须 ≥ `strlen(s) + 1` |

---

### 八、一句话总结

- 读字符串：用 `fgets`（安全）或 `scanf("%s")`（简单但不读空格）
- 比较字符串：用 `strcmp`
- 拷贝字符串：用 `strcpy`
- 遍历字符：用 `for (int i = 0; s[i] != '\0'; i++)`
- 每个字符串数组永远多留 1 位给 `'\0'`