//(1)思路：双指针k和i，k指向顺序表中不在s和t之间的最后一个元素位置，i用于遍历数组，当元素在s和t之间时跳过，当元素不在s和t之间时将元素赋值给k指向的位置，k++，i++。最后更新顺序表的长度为k+1

//(2)代码：
#include<stdio.h>
#define MaxSize 100

typedef struct{
  int data[MaxSize];
  int length;
}Sqlist;

void del_between(Sqlist *L,int s,int t){
  int k = -1;
  for(int i = 0;i < L->length;++i){
    if(L->data[i] < s || L->data[i] > t){
      L->data[++k] = L->data[i];
    }
  }
  L->length = k + 1;
}

//(3)时间复杂度: O(n) 空间复杂度: O(1)