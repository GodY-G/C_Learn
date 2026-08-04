//非递归先序遍历
#include<stdio.h>

typedef struct LNode{
  int data;
  struct LNode *lchild,*rchild;
}LNode,*BiTree;

void PreOrder1(BiTree t){
  printf("%d",t->data);
  PreOrder(t->lchild);
  PreOrder(t->rchild);
}

void PreOrder2(BiTree t){
  if(t == NULL)return;
  BiTree stack[100];
  int top = -1;
  stack[++top] = t;
  while(t){
    BiTree p = stack[top--];
    printf("%d",p->data);
    if (p->rchild)stack[++top] = p->rchild;
    if(p->lchild)stack[++top] = p->lchild;
  }
}
