//(1)思路：逆置三段法,先后逆置前m数组，后n数组，以及整个数组

//(2)代码：

#include <stdio.h>
#define MaxSize 100

typedef struct {
    int data[MaxSize];
    int length;
} Sqlist;

void reverse(Sqlist *L, int start, int end) {
    int i = start;
    int j = end;
    while (i < j) {
        int temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
        i++;
        j--;
    }
}

void exchange(Sqlist *L,int m,int n){
  reverse(L,0,m-1);
  reverse(L,m,m+n-1);
  reverse(L,0,m+n-1);
}

//(3)时间复杂度: O(m+n) 空间复杂度: O(1)