//(1)思路：初始化两个头节点A和B，分别将A和B从原链表中分离出奇偶子列，再将B原地逆置

//(2)代码：
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 把 C 拆成两个链表，A 和 B 用参数传出
void split(LinkList C, LinkList *A, LinkList *B) {
    // 1. 创建 A、B 的头结点
    *A = (LinkList)malloc(sizeof(LNode));
    *B = (LinkList)malloc(sizeof(LNode));
    (*A)->next = NULL;
    (*B)->next = NULL;

    LNode *tailA = *A;     // A 的尾指针（尾插法用）
    LNode *tailB = *B;     // B 的尾指针
    LNode *p = C->next;    // 从第一个数据结点开始
    int i = 1;

    // 2. 按位置奇偶拆分
    while (p != NULL) {
        LNode *next = p->next;   // 先保存后继，p 马上要被摘走
        p->next = NULL;          // 摘下 p，断掉和原链表的联系

        if (i % 2 == 1) {        // 奇数位置 → 尾插到 A
            tailA->next = p;
            tailA = p;
        } else {                 // 偶数位置 → 尾插到 B
            tailB->next = p;
            tailB = p;
        }

        p = p->next;
        i++;
    }

    // 3. 尾结点的 next 已经在上面的 p->next = NULL 处理了
    // 现在逆置 B（头插法）
    LNode *cur = (*B)->next;
    (*B)->next = NULL;
    while (cur != NULL) {
        LNode *next = cur->next;
        cur->next = (*B)->next;
        (*B)->next = cur;
        cur = next;
    }
}
//(3)时间复杂度：O(n)，空间复杂度：O(1)