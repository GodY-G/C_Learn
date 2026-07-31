#include<stdio.h>
//倒数第k个元素

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*Linklist;

LNode *find_last_k(Linklist L,int k){
  if(L->next == NULL || k <= 0)return NULL;
  LNode *p = L->next,*q = L->next;
  for(int i = 0;i < k - 1;i++){
    if(q->next != NULL)q = q->next;
    else return NULL;
  }
  while(q->next != NULL){
    p = p->next;
    q = q->next;
  }
  return p;
}

//查找中间元素
LNode *find_middle(Linklist L){
  if(L->next == NULL)return NULL;
  LNode *p = L->next,*q = L->next;
  while(q->next != NULL && q->next->next != NULL){
    p = p->next;
    q = q->next->next;
  }
  return p;
}
