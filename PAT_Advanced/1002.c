#include<stdio.h>

int main(){
  int k,exp;
  double coe;
  double coef[1001] = {0.0};

  //第一个多项式
  scanf("%d",&k);
  for(int i = 0; i < k;++i){
    scanf("%d %lf",&exp,&coe);
    coef[exp] += coe;
  }

  //第二个多项式
  scanf("%d",&k);
  for(int i = 0; i < k;++i){
    scanf("%d %lf",&exp,&coe);
    coef[exp] += coe;
  }

  int cnt = 0;
  for(int i = 0;i < 1001;++i){
    if(coef[i]!= 0){
      cnt++;
    }
  }
  printf("%d",cnt);
  for(int i = 1000;i >= 0;--i){
    if(coef[i] != 0){
      printf("%d %.1lf",i,coef[i]);
    }
  }

  return 0;
}