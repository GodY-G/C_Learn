#include<stdio.h>

int main(){
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        float x;
        scanf("%f", &x);
        if(x >= 0&&x < 2){
         printf("y=%.1f\n",-1*x+2.5);
        }
        else if(x >= 2 && x < 4){
          printf("y=%.1f\n",2 - 1.5 * (x - 3) * (x - 3));
        }
        else if(x >= 4 && x < 6){
          printf("y=%.1f\n",x / 2.0 - 1.5);
        } 
    }
  
    return 0;
}