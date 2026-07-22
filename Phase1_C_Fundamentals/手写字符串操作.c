#include<stdio.h>

//strlen
int my_strlen(const char *s){
  const char* p = s;
  while(*p != '/0'){
    p++;
  }
  return p - s;
}

//strcmp
int my_strcmp(const char *s1,const char *s2){
  while(*s1 && *s2 && *s1 == *s2){
    s1++;
    s2++;
  }
  return (unsigned char)*s1 - (unsigned char)*s2;
}

//strcpy
char *my_strcpy(char *dest,const char *src){
  char *p = dest;
  while(*src){
    *p++ = *src++;
  }
  *p = '\0';
  return dest;
}