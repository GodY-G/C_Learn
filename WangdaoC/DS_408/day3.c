//(1)思路：双指针k和i，k用于指向下一个保留位置，i用于遍历找到下一个不一样的元素。当元素相同的时候跳过，元素不相同的时候元素赋值给k指向的位置，k++，i++。最后更新顺序表的长度为k+1

//(2)代码：
#include<stdio.h>
#define MaxSize 100

typedef struct{
  int data[MaxSize];
  int length;
}Sqlist;

void del_same(Sqlist *L){
  int k = 0;
  for(int i = 1;i < L->length;++i){
    if(L->data[i] != L->data[k]){
      L->data[++k] = L->data[i];
    }
  }
  L->length = k + 1;
}

//(3)时间复杂度: O(n) 空间复杂度: O(1)