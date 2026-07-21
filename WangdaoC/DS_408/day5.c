//(1)思路：双指针k和i，k指向下一个保留位置，i用于遍历有序表中不在s和t之间的元素

//(2)代码：
#include<stdio.h>
#define MaxSize 100

typedef struct{
  int data[MaxSize];
  int length;
}Sqlist;

void del_between(Sqlist *L,int s,int t){
  int k = 0;
  int i = 0;
  while(L->data[i] < s)i++;
  k = i;
  while(L->data[i] <= t)i++;
  for(int j = i;j < L->length;j++){
    L->data[k++] = L->data[j];
  }
  L->length = k;
}

//(3)时间复杂度: O(n) 空间复杂度: O(1)