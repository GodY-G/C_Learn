//(1)思路：定义三个指针，cur指向当前节点，pre指向当前节点的前一个节点，next指向当前节点的下一个节点。逆置链表。

//(2)代码
#include<stdio.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*Linklist;

Linklist reverse_3ptr(Linklist L){
  LNode *pre = NULL;
  LNode *cur = L->next;
  LNode *next = NULL;
  while(cur){
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }
  L->next = pre;
  return L;
}
//改进写法：
/*
while(cur){
  LNode *next = cur->next;
  cur->next = pre;
  pre = cur;
  cur = next;
}
*/
//(3)时间复杂度O(n) 空间复杂度O(1)