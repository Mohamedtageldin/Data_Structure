#include "Expression_Evaluation.h"

long long evaluate(char* Expression,int Size){
    ST_queueInfo Queue;
    int Oper=0, Counter=0;
    long long Operand1=0, Operand2=0;
    int* Oper_Ptr=&Oper;
    if(checkForBalancedParantheses(Expression)){
    createQueue(&Queue,Size);
    while (Expression[Counter]!='\0'){
    while((Expression[Counter]>47)&&(Expression[Counter]<58)){
          if(0==Operand1){
          Operand1=(Operand1*10)+(Expression[Counter]-48);
            }else{
                Operand2=(Operand2*10)+(Expression[Counter]-48);
            }
          }
          if((43==Expression[Counter])||(42==Expression[Counter])||(45==Expression[Counter])||(47==Expression[Counter])){
            enqueue(&Queue,Expression[Counter]);
            if(!Q_Is_Empty(&Queue)){
                dequeue(&Queue,Oper_Ptr);
                if(43==Expression[Counter])
                Operand1=Operand1+Operand2;
                if(45==Expression[Counter])
                Operand1=Operand1-Operand2;
                if(42==Expression[Counter])
                Operand1=Operand1*Operand2;
                if(47==Expression[Counter])
                Operand1=Operand1/Operand2;
            }
          }
     Counter++;
 }

 }
 return Operand1;
}
void main (){
char string []="(3+3+3)";
printf("%d",evaluate(string,9));
}
