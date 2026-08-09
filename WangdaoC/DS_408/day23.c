//模板:求二叉树的深度(递归)
#include <stdio.h>

typedef struct BitNode{
  int data;
  struct BitNode *lchild, *rchild;
}BitNode,*BitTree;

int Depth(BitTree T){
  if(T == NULL) return 0;
  int ld = Depth(T->lchild);
  int rd = Depth(T->rchild);

  return (ld > rd ? ld : rd) + 1;
}
