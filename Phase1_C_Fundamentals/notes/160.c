#include<stdio.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };

  struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA || !headB)return NULL;//若链表为空

    int lenA = 0,lenB = 0;//计算两个链表的长度
    struct ListNode* p = headA;
    while (p)
    {
      lenA++;
      p = p->next;
    }
    p = headB;
    while(p){
      lenB++;
      p = p->next;
    }

    struct ListNode* curA = headA, *curB = headB;//抹除两个链表之间的差值
    if(lenA > lenB){
      int diff = lenA - lenB;
      while(diff--){
        curA = curA->next;
      }
    }else if(lenB > lenA){
      int diff = lenB - lenA;
      while(diff--){
        curB = curB->next;
      }
    }
    
    while(curA && curB){//同时遍历两个链表
      if(curA == curB){
        return curA;
      }
      curA = curA->next;
      curB = curB->next;
    }
    return NULL;
  }