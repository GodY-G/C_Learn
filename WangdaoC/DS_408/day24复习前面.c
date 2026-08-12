#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

 //链表逆置(头插法)
void reverse_head(Linklist L){
  Linklist p =  L->next;
  L->next = NULL;
  while(p){
    Linklist q = p->next;
    p->next = L->next;
    L->next = p;
    p = q;
  }
}

//链表逆置三指针法
void reverse_3ptr(Linklist L){
  Linklist work = L->next;
  Linklist pre = NULL;
  while(work){
    Linklist next = work->next;
    work->next = pre;
    pre = work;
    work = next;
  }
  L->next = pre;
}

//删除链表中全部的x
void del_X(Linklist L,int x){
  Linklist p = L->next;
  while(p->next){
    if(p->next->data == x){
      p = p->next;
      Linklist q = p->next;
      p->next = q->next;
      free(q);
    }else{
      p = p->next;
    }
  }
}

//找到倒数第k个节点
int last_k(Linklist L,int k){
  Linklist fast = L->next,slow = L->next;
  int cnt = 0;
  while(cnt < k && fast){
    fast = fast->next;
    cnt++;
  }
  if(cnt < k)return -1;
  while(fast){
    fast = fast->next;
    slow = slow->next;
  }
  return slow->data;
}

//找到中间节点
int find_mid(Linklist L){
  Linklist p = L->next,q = L->next;
  while(p && p->next){
    p = p->next->next;
    q = q->next;
  }
  return q->data;
}

//判断是否有环
LNode* has_cycle(Linklist L) {
    LNode *fast = L, *slow = L;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return slow;  // 相遇，有环
    }
    return NULL;
}

//找到环入口
LNode* find_cycle_entry(Linklist L) {
    LNode *meet = has_cycle(L);
    if (meet == NULL) return NULL;
    LNode *p = L;
    while (p != meet) {  // 头到入口 = 相遇点到入口
        p = p->next;
        meet = meet->next;
    }
    return p;
}

//合并两个升序链表
Linklist combine_2linklist(Linklist A, Linklist B) {
    Linklist C = (Linklist)malloc(sizeof(LNode));
    C->next = NULL;
    Linklist pc = C;                   // pc 指向头结点，不是 C->next！
    Linklist pa = A->next, pb = B->next;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;             // 先接到 C 上
            pc = pa;                   // 再后移
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = (pa ? pa : pb);         // 剩余直接接上
    return C;
}Linklist combine_2linklist(Linklist A, Linklist B) {
    Linklist C = (Linklist)malloc(sizeof(LNode));
    C->next = NULL;
    Linklist pc = C;                   // pc 指向头结点，不是 C->next！
    Linklist pa = A->next, pb = B->next;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;             // 先接到 C 上
            pc = pa;                   // 再后移
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = (pa ? pa : pb);         // 剩余直接接上
    return C;
}
