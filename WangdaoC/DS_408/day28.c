#include<stdio.h>

typedef struct BitNode{
  int data;
  struct BitNode* lchild;
  struct BitNode* rchild;
}BitNode,*BiTree;

//BST查找
BiTree BST_Node(BiTree T,int key){
  if(T == NULL || T->data == key)return T;
  if(T->data > key) return BST_Node(T->lchild,key);
  else return BST_Node(T->rchild,key);
}

//BST插入
int BST_insert(BiTree *T,int key){
  if(T == NULL){
    *T = (BiTree)malloc(sizeof(BitNode));
    (*T)->data = key;
    (*T)->lchild = (*T)->rchild = NULL;
    return 1;
  }
  if((*T)->data == key)return 0;
  if((*T)->data<key) return BST_insert(&(*T)->rchild,key);
  else return BST_insert(&(*T)->lchild,key);
}