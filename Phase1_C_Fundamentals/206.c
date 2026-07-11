/**
 * Definition for singly-linked list.
 */
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    //判空
    if (head == NULL || head->next == NULL) return head;
    
    struct ListNode *prev = NULL;   // 前驱指针，初始为NULL
    struct ListNode *curr = head;   // 当前指针
    struct ListNode *next;          // 后继指针
    
    //循环反转
    while (curr != NULL) {
        next = curr->next;          // 保存下一个节点
        curr->next = prev;          // 反转当前节点的指针
        prev = curr;                // prev 后移
        curr = next;                // curr 后移
    }
    
    return prev; 
}