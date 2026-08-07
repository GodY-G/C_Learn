#include<stdio.h>

typedef struct BiNode{
  int data;
  struct BiTree *lchild,*rchild;
}BiNode,*BiTree;

//二叉树的先序遍历
void PreOrder(BiTree T){
  if(T == NULL)return;
  //访问节点；
  printf("%d",T->data);
  PreOrder(T->lchild);
  PreOrder(T->rchild);
}

//二叉树的中序遍历
void InOrder(BiTree T){
  if(T == NULL)return;
  InOrder(T->lchild);
  printf("%d",T->data);
  InOrder(T->rchild);
}

//二叉树的后序遍历
void PostOrder(BiTree T){
  if(T == NULL)return;
  PostOrder(T->lchild);
  PostOrder(T->rchild);
  printf("%d",T->data);
}

//计算二叉树的深度
int depth(BiTree T){
  if(T == NULL)return 0;
  int ld = depth(T->lchild);
  int rd = depth(T->rchild);
  return (ld > rd ? ld : rd) + 1;
}