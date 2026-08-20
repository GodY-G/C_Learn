#include<stdio.h>
#define maxsize 100
//层序遍历
typedef struct BitNode{
  int data;
  struct BitNode *lchild; 
  struct BitNode *rchild; 
}BitNode,*BitTree;

void LevelOrder(BitTree T) {
    if (T == NULL) return;
    BitTree Q[maxsize];     // 用数组模拟队列
    int front = 0, rear = 0;
    Q[rear++] = T;         // 根入队
    while (front < rear) {
        BitTree p = Q[front++];   // 出队
        visit(p);
        if (p->lchild) Q[rear++] = p->lchild;
        if (p->rchild) Q[rear++] = p->rchild;
    }
}