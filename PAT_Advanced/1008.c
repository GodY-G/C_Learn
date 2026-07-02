#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int total_time = 0;
    int temp = 0;
    for(int i = 0;i < n;++i){
        int floor = 0;
        int minus = 0;
        scanf("%d",&floor);
        minus = floor - temp;
        temp = floor;
        if(minus > 0){
            total_time += 6 * minus;
        }
        if(minus < 0){
            total_time += -4 * minus;
        }
        total_time += 5;
    }

    printf("%d\n",total_time);

    return 0;
}