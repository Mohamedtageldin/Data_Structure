#ifndef STACK_H_
    #define STACK_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct ST_stackInfo{
    int* Ptr;
    int Num_OfElements;
    int Size;
}ST_stackInfo;
void CreateStack(ST_stackInfo* , int);
void Push(ST_stackInfo* , int );
void Pop(ST_stackInfo* , int* );
int Peak(ST_stackInfo *info);
char Is_Empty(ST_stackInfo *info);
unsigned char checkForBalancedParantheses(char* expression);

#endif // STACK_H_
