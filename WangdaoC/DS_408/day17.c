//(1)思路：双指针，一个工作指针work，一个前驱指针pre，work指针用于遍历整个链表，遍历到范围内的值就更新指针,释放内存

//(2)代码:
#include<stdio.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*Linklist;

void solution(Linklist L,int min,int max){
  if(L->next == NULL)return;
  Linklist work = L;
  while(work->next){
    if(work->next->data >= min && work->next->data <= max){
      Linklist q = work->next;
      work->next = q->next;
      free(q);
    }else{
      work = work->next;
    }
  }
}
//(3)时间复杂度O(N),空间复杂度O(1)