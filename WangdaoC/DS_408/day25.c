//求二叉树深度
#include<stdio.h>

typedef struct BitNode{
  int data;
  struct BitNode* lchild;
  struct BitNode* rchild;
}BitNode,*BiTree;

int depth(BiTree root){
  if(root == NULL)return 0;
  int ld = depth(root->lchild);
  int rd = depth(root->rchild);
  return (ld > rd ? ld : rd) + 1;
}

//结点总数
int count(BiTree root){
  if(root == NULL)return 0;
  return count(root->lchild) + count(root->rchild) + 1;
}

//叶子节点总数
int count_leaf(BiTree root){
  if(root == NULL)return 0;
  if(root->lchild == NULL && root->rchild == NULL)return 1;
  return count_leaf(root->lchild) + count_leaf(root->rchild);
}

//判相同
int is_same(BiTree T1,BiTree T2){
  if(T1 == NULL && T2 == NULL) return 1;
  if(T1 == NULL || T2 == NULL) return 0;
  if(T1->data != T2->data) return 0;
  return is_same(T1->lchild,T2->lchild) && is_same(T1->rchild,T2->rchild);
}