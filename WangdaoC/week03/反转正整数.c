#include<stdio.h>

int reverse(int n){
    int res = 0;
    while(n > 0){
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        printf("%d ", reverse(num));
    }
    return 0;
}