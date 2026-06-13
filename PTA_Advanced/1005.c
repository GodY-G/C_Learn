#include<stdio.h>

int main(){
  char s[105];
  scanf("%s",s);

  int sum = 0;
  for(int i = 0;s[i]!= '\0';++i){
    sum += s[i] - '0';
  }

  const char* n[10] ={
    "zero","one","two","three","four",
    "five","six","seven","eight","nine"
  };

  if(sum == 0){
    printf("zero");
    return 0;
  }

  int digits[10],cnt = 0;
  while(sum){
    digits[cnt++] = sum % 10;
    sum /= 10;
  }

  for(int i = cnt - 1;i >= 0;--i){
    printf("%s",n[digits[i]]);
    if(i > 0)printf(" ");
  }




  return 0;
}