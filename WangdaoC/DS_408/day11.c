//(1)思路：利用二分查找法在有序顺序表中查找元素x，如果找到，则将其与后继元素交换位置；如果未找到，则将x插入到合适的位置，保持顺序表的有序性。

//(2)代码
#include<stdio.h>
#define MaxSize 100

typedef struct {
    int length;
    int data[MaxSize];
} Sqlist;

void solution(Sqlist *L,int x){
  int i = 0,j = L->length - 1;
  int idx = -1;
  while(i <= j){
    int mid = (i + j) / 2;
    if(L->data[mid] == x){
      idx = mid;
      break;
  }else if(L->data[mid] < x){
      i = mid + 1;
}else{
      j = mid - 1;
    }
  }
  if(idx != -1){
    if(idx < L->length - 1){
      int temp = L->data[idx];
      L->data[idx] = L->data[idx + 1];
      L->data[idx + 1] = temp;
    }
    
  }else{
    if (L->length >= MaxSize) return;
    for(int k = L->length;k > i;k--){
      L->data[k] = L->data[k - 1];
    }
    L->data[i] = x;
    L->length++;
  }
}

//(3)时间复杂度O(n) 空间复杂度O(1)