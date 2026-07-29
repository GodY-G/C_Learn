//(1)思路：初始化双指针，一个工作指针work，一个前驱指针minptr，work指针用于遍历整个链表，遍历到更小值就更新指针

//(2)代码:
#include<stdio.h>
#include <limits.h>  

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*Linklist;

void solution(Linklist L){
  if (L->next == NULL) return;
  Linklist work = L;
  Linklist minptr = NULL;
  int min = INT_MAX;

  while(work->next){
    if(min > work->next->data){
      minptr = work;
      min = work->next->data;
    }
    work = work->next;
  }
  Linklist del = minptr->next;
  minptr->next = minptr->next->next;
  free(del);
}

//(3)时间复杂度O(N),空间复杂度O(1)