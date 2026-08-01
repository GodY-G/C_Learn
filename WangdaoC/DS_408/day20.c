//思路：初始化三个指针，pa，pb，pc分别指向A,B的头节点，pc指向新链表的尾节点。每次比较大小，将较小的节点放到新链表上。当其中一个链表为空时，将另一个链表的剩余部分直接接到新链表上。


//代码：
#include <stdio.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*Linklist;

void merge(Linklist A,Linklist B,Linklist C){
  LNode *pa = A->next,*pb = B->next,*pc = C;
  while(pa != NULL && pb != NULL){
    if(pa->data <= pb->data){
      pc->next = pa;
      pc = pa;
      pa = pa->next;
    }else{
      pc->next = pb;
      pc = pb;
      pb = pb->next;
    }
  }
  if(pa != NULL)pc->next = pa;
  if(pb != NULL)pc->next = pb;
}