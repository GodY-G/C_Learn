#include <stdbool.h>
bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for(int i = 0;i < len;++i){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[++top] = s[i];
        }else{
            if(top == -1)return false;
            char left = stack[top--];
            if(s[i] == ')' && left != '(')return false;
            if(s[i] == ']' && left != '[')return false;
            if(s[i] == '}' && left != '{')return false;
         }
    }
    return top == -1;
}