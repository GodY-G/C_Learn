//(1)思路：遍历整个链表，删除所有值为x的节点，并释放其内存空间。


//(2)代码
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*Linklist;

void del_X(Linklist L,int x){
  LNode *p = L;
  while(p->next){
    if(p->next->data == x){
      LNode *q = p->next; 
      p->next = q->next;
      free(q);
    }else{
      p = p->next;
    }
  }
}

//(3)时间复杂度O(n) 空间复杂度O(1)