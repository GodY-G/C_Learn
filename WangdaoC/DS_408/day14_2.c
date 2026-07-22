//(1)思路：采用头插法，将链表逆置。定义两个指针，cur指向当前节点，next指向后一个节点。依次插入到头节点之后。

//(2)代码
#include<stdio.h>
typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*Linklist;

Linklist reverse_head(Linklist L){
  LNode *cur = L->next;
  L->next = NULL;
  while(cur){
    LNode* next = cur->next;
    cur->next = L->next;
    L->next = cur;
    cur = next;
  }
  return L;
}

//(3)时间复杂度O(n) 空间复杂度O(1)