#include "Stack.h"

void CreateStack(ST_stackInfo *info, int size){
   info->Ptr=(int*)malloc(size*sizeof(*(info->Ptr)));
   info->Num_OfElements=0;
   info->Size=size;
}
void Push(ST_stackInfo *info, int data){
    if(info->Num_OfElements!=info->Size){
    if(0==info->Num_OfElements){
        *(info->Ptr)=data;
        (info->Num_OfElements)++;
    }else{
        (info->Ptr)++;
        *(info->Ptr)=data;
        (info->Num_OfElements)++;

        }
    }else{
        printf("Stack is Full");
    }
}
void Pop(ST_stackInfo *info, int* data){
    if(0!=info->Num_OfElements){
        *data=*(info->Ptr);
        (info->Ptr)--;
        (info->Num_OfElements)--;

    }else{

    printf("Stack is empty");
    }
}
int Peak(ST_stackInfo *info){
    if(0!=info->Num_OfElements){
        return*(info->Ptr);
    }else{
    printf("Stack is empty");
    }
}
char Is_Empty(ST_stackInfo *info){
if(0==info->Num_OfElements){
    return 1;
}
    return 0;
}
unsigned char checkForBalancedParantheses(char* expression){
    ST_stackInfo Stack_Open;
    int Counter=0, Data_Pop;
    int* Ptr_DataPop;
    Ptr_DataPop=&Data_Pop;
    CreateStack(&Stack_Open,9);
    while(expression[Counter]!='\0'){
        if((40==(int)expression[Counter])||(91==(int)expression[Counter])||(123==(int)expression[Counter])){       /*Open Parenthesis*/
                Push(&Stack_Open,(int)expression[Counter]);
        }else{


            if((41==(int)expression[Counter])||(93==(int)expression[Counter])||(125==(int)expression[Counter])){   /*Closed Parenthesis*/
                    if((0==Counter)||(Is_Empty(&Stack_Open))){
                        return (unsigned char)0;
                    }
                    if(41==(int)expression[Counter]){
                        Pop(&Stack_Open,Ptr_DataPop);
                        if(*Ptr_DataPop!=40){
                            return (unsigned char)0;
                        }
                    }
                    if(93==(int)expression[Counter]){
                        Pop(&Stack_Open,Ptr_DataPop);
                        if(*Ptr_DataPop!=91){
                            return (unsigned char)0;
                        }
                    }
                    if(125==(int)expression[Counter]){
                        Pop(&Stack_Open,Ptr_DataPop);
                        if(*Ptr_DataPop!=123){
                            return (unsigned char)0;
                        }
                    }
            }
        }
        Counter++;
    }
    if(Is_Empty(&Stack_Open))
    return (unsigned char)1;
    return (unsigned char)0;
}
/*
void main(){
char Parenthesis[]="()(){}{)";
printf("%d \n",checkForBalancedParantheses(Parenthesis,8));
}*/
