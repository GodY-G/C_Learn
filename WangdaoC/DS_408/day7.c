//(1)思路:双指针i和j，i指向首位，j指向最后一个位置，i向后遍历，j向前遍历，相互交换数据

//(2)代码:
#include<stdio.h>
#define MaxSize 100
typedef struct{
  int data[MaxSize];
  int length;
}Sqlist;

void reverse(Sqlist * L){
  int i = 0;
  int j = L->length - 1;
  while(i < j){
    int temp = L->data[i];
    L->data[i] = L->data[j];
    L->data[j] = temp;
    i++;
    j--;
  }
}

//(3)时间复杂度: O(n) 空间复杂度: O(1)