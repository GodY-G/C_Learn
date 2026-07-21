//链表的遍历
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*Linklist;

void through(Linklist L){
  LNode *p = L;
  while(p->next){
    printf("%d ",p->data);
    p = p->next;
  }
}