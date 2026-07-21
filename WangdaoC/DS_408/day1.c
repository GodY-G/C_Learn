//(1)思路：删除顺序表中唯一的最小值。   设置双指针min_idx和i，min_idx指向最小值的下标，min保存最小值。遍历顺序表，若当前元素小于min，则更新min和min_idx。最后将顺序表中最小值所在位置的元素替换为顺序表最后一个元素，并将顺序表长度减1。


//(2)代码
#include<stdio.h>
#define MaxSize 100

typedef struct{
  int data[MaxSize];
  int length;
}Sqlist;

int Delete_min(Sqlist *L){
  if(L->length == 0){
    printf("error\n");
    return 0;
  }
  int min = L->data[0];
  int min_idx = 0;
  for(int i = 0;i<L->length;++i){
    if(L->data[i] < min){
      min = L->data[i];
      min_idx = i;    
      }
  }
  L->data[min_idx] = L->data[L->length-1];
  L->length--;
  return min;
}

//(3)复杂度 时间复杂度: O(n) 空间复杂度: O(1)