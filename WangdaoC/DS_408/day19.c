//思路：设置快慢双指针，fast指针每次移动两个位置，slow指针每次移动一个位置，如果最终有fast和slow指向同一个元素，则有环

//代码：
#include <stdio.h>
#include <stdbool.h>
typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*Linklist;

bool is_circular(Linklist L){
  if(L->next == NULL)return false;
  LNode *slow = L->next,*fast = L->next;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)return true;
  }
  return false;
}

//时间复杂度：O(n)，空间复杂度：O(1)