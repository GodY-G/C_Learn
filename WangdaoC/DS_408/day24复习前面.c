#include<stdio.h>
#include<stdlib.h>

#define maxsize 100

//一.结构体定义

//顺序表
typedef struct {
  int data[maxsize];
  int length;
}Sqlist;

//单链表
typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*Linklist;

//双链表
typedef struct DNode{
  int data;
  struct DNode *prev,*next;
}DNode,*Dlinklist;

//二叉树
typedef struct BitNode{
  int data;
  struct BitNode *lchild,*rchild;
}BitNode,*BitTree;


//二.算法实现

//双指针删除元素
void del_x(Sqlist *L,int x){
  int k = 0;
  for(int i = 0;i < L->length;++i){
    if(L->data[i] != x){
      L->data[k++] = L->data[i];
    }
  }
  L->length = k;
}

//删除所有重复元素(有序表)
void del_same(Sqlist *L){
  int k = 0;//指向最后一个不重复的元素位置
  for(int i = 1;i < L->length;++i){
    if(L->data[i] != L->data[k]){
      L->data[++k] = L->data[i];
    }
  }
  L->length = k + 1;
}

//顺序表逆置
void reverse(Sqlist *L){
  int i = 0;
  int j = L->length - 1;
  while(i < j){
    int temp = L->data[i];
    L->data[i] = L->data[j];
    L->data[j] = temp;
    ++i;
    --j;
  }
}

//有序顺序表合并
Sqlist merge(Sqlist a,Sqlist b){
  Sqlist c;
  c.length = 0;
  int i = 0,j = 0;
  while(i < a.length && j < b.length){
    if(a.data[i] <= b.data[j]){
      c.data[c.length++] = a.data[i];
      ++i;
    }else{
      c.data[c.length++] = b.data[j];
      ++j;
    }
  }
  while(i < a.length)c.data[c.length++] = a.data[i++];
  while(j < b.length)c.data[c.length++] = b.data[j++];
  return c;
 }

 //二分查找
 int binsearch(Sqlist L,int x){
  int low = 0,high = L.length - 1;
  while(low <= high){
    int mid = (high - low) / 2 + low;
    if((L.data[mid] == x))return mid;
    else if(L.data[mid] < x)low = mid + 1;
    else high = mid - 1;
  }
  return -1;
 }