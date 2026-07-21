//(1)思路：删除顺序表中的元素x。      设置双指针k和i，k指向保留位置，i指向遍历位置，遍历到等于x则跳过

//(2)代码
#include<stdio.h>
#define MaxSize 100

typedef struct{
  int data[MaxSize];
  int length;
}Sqlist;

void del_x(Sqlist *l,int x){
  Sqlist *L = L;
  int k = 0;
  for(int i = 0;i < L->length;++i){
    if(L->data[i] != x){
      L->data[k++] = L->data[i];
    }
  }
  L->length = k;
}

//(3)复杂度 时间复杂度: O(n) 空间复杂度: O(1)