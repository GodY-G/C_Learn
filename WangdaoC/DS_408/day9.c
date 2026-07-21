//(1)思路：新建一个新数组，双指针分别遍历两个数组，将两个数组的元素依次放入新数组中

//(2)代码：
#include <stdio.h>
#define MaxSize 100

typedef struct {
    int data[MaxSize];
    int length;
} Sqlist;

Sqlist merge(Sqlist A,Sqlist B){
  Sqlist C;
  C.length = 0;
  int i = 0, j = 0;
  while(i < A.length && j < B.length){
    if(A.data[i] <= B.data[j]){
      C.data[C.length++] = A.data[i++];
    }else{
      C.data[C.length++] = B.data[j++];
    }
  }
  while(i < A.length){
    C.data[C.length++] = A.data[i++];
  }
  while (j < B.length){
    C.data[C.length++] = B.data[j++];
  }
  return C;
}

//(3)时间复杂度: O(m+n) 空间复杂度: O(m+n)