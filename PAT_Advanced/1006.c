#include<stdio.h>
#include<string.h>

int main(){
    int m;
    scanf("%d",&m);

    char id_in[16],id_out[16];
    char time_in[10],time_out[10];
    char in[10],out[10],id[16];

    scanf("%s %s %s",id,in,out);
    strcpy(id_in,id);
    strcpy(id_out,id);
    strcpy(time_in,in);
    strcpy(time_out,out);

    for(int i = 1;i < m;++i){
        scanf("%s %s %s",id,in,out);

        if(strcmp(in,time_in)<0){
            strcpy(id_in,id);
            strcpy(time_in,in);
        }
        if(strcmp(out,time_out)>0){
            strcpy(id_out,id);
            strcpy(time_out,out);
        }

    }
    printf("%s %s",id_in,id_out);
    return 0;
}