#include<stdio.h>
#define maxsize 100
typedef struct BitNode{
  int data;
  struct BitNode *lchild;
  struct BitNode *rchild;
}BitNode,*BiTree;

//非递归中序遍历

void Inorder(BiTree T){
  BiTree stack[maxsize];
  int top = -1;
  BiTree p = T;
  while(p != NULL || top != -1){
    if(p != NULL){
      stack[++top] = p;
      p = p->lchild;
    }else{
      p = stack[top--];
      visit(p);
      p = p->rchild;
    }
  }
}

//非递归先序遍历
void PreOrder(BiTree T){
  if(T == NULL) return;
  BiTree stack[maxsize];
  int top = -1;
  stack[++top] = T;
  while(top != -1){
    BiTree p = stack[top--];
    visit(p);
    if(p->rchild) stack[++top] = p->rchild;
    if(p->lchild) stack[++top] = p->lchild;
  }
}

//层次遍历
void levelorder(BiTree T){
  if(T == NULL)return;
  BiTree Q[maxsize];
  int front = 0,rear = 0;
  Q[rear++] = T;
  while(front < rear){
    BiTree p = Q[front++];
    visit(p);
    if(p->lchild)Q[rear++] = p->lchild;
    if(p->rchild)Q[rear++] = p->rchild;
  }
}