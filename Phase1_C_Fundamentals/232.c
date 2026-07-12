#include<stdio.h>
#include<stdbool.h>
//栈的结构体定义
typedef struct{
  int* stk;
  int stksize;
  int stktop;
}Stack;

Stack* stackCeate(int size){
  Stack* s = (Stack*)malloc(sizeof(Stack));
  s->stk = (int*)malloc(sizeof(int)*size);
  s->stksize = 0;
  s->stksize = size;
  return s;
}

void stackPush(Stack* obj,int x){
  obj->stk[++obj->stktop] = x;
}

void stackPop(Stack* obj){
  obj->stksize--;
}

int stackTop(Stack* obj) {
    return obj->stk[obj->stksize - 1];  
}

bool stackEmpty(Stack* obj) {
    return obj->stksize == 0;
}

void stackFree(Stack* obj) {
    free(obj->stk);   
}

//队列结构体
typedef struct {
    Stack* inStack;   
    Stack* outStack;  
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* ret = malloc(sizeof(MyQueue));
    ret->inStack = stackCreate(100);   
    ret->outStack = stackCreate(100);  
    return ret;
}

void in2out(MyQueue* obj) {
    while (!stackEmpty(obj->inStack)) {        
        stackPush(obj->outStack, stackTop(obj->inStack));
        stackPop(obj->inStack);                  
    }
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->inStack, x);    
}

int myQueuePop(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {   
        in2out(obj);                    
    }
    int x = stackTop(obj->outStack);   
    stackPop(obj->outStack);          
    return x;
}

int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    return stackTop(obj->outStack);    
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(obj->inStack) && stackEmpty(obj->outStack);
    
}

void myQueueFree(MyQueue* obj) {
    stackFree(obj->inStack);    
    stackFree(obj->outStack);   
    free(obj);                  
}