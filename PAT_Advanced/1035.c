#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();  // 吃掉 scanf 残留的换行符

    char teams[1000][11];    // 存所有被修改的用户名
    char passwords[1000][11]; // 存所有被修改的密码
    int cnt = 0;              // 被修改的账号数量

    for (int i = 0; i < n; i++) {
        char name[11], pwd[11];
        scanf("%s %s", name, pwd);  // 读入用户名和密码

        bool changed = false;
        for (int j = 0; pwd[j] != '\0'; j++) {
            if (pwd[j] == '1') { pwd[j] = '@'; changed = true; }
            if (pwd[j] == '0') { pwd[j] = '%'; changed = true; }
            if (pwd[j] == 'l') { pwd[j] = 'L'; changed = true; }
            if (pwd[j] == 'O') { pwd[j] = 'o'; changed = true; }
        }

        if (changed) {
            strcpy(teams[cnt], name);
            strcpy(passwords[cnt], pwd);
            cnt++;
        }
    }

    // 输出结果
    if (cnt == 0) {
        if (n == 1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n", n);
    } else {
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++) {
            printf("%s %s\n", teams[i], passwords[i]);
        }
    }

    return 0;
}