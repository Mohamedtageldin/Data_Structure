#include "Queue.h"
void createQueue(ST_queueInfo* info, int maxSize){
    info->Reference=malloc(maxSize*sizeof(*(info->Reference))); /*Hold the address of the first element in the array*/
    info->Max_Size=maxSize;                         /*Maximum size of the queue*/
    info->Front=info->Reference;                    /*Hold address of the first element enqueued*/
    info->Rear=info->Reference;                        /*Hold address of the last element enqueued*/
    info->Num_OfElements=0;                             /*Hold Number of elements inserted in the queue*/
}
void enqueue(ST_queueInfo *info, int data){
    if(info->Num_OfElements!=info->Max_Size){           /*Check if the queue is full*/
        if(((info->Rear)-(info->Reference))+1==info->Max_Size){/*Circulate the Rear pointer in the array of the queue if it pass the max size of the array*/
            info->Rear=info->Reference;                     /*Circulate the rear pointer in the array of the queue*/
        }else{
            if(0!=info->Num_OfElements){    /*check the queue is empty or not to increment the rear because it initialized on the first index*/
            (info->Rear)++;                 /*increment the rear to point to the next index*/
            }
        }
        *(info->Rear)=data;         /*Save the data in the queue*/
        (info->Num_OfElements)++;   /*Increment the number of elements inserted*/
    }else{
        printf("The Queue is Full");    /*The Queue is Full*/
    }
}
void dequeue(ST_queueInfo *info, int* data){
if(info->Num_OfElements!=0){            /*Check if the queue is empty*/
        *data=*(info->Front);               /*Assign the value of the data to the pointer passed in argument*/
    if(((info->Front)-(info->Reference))+1==info->Max_Size){       /*check if the front arrives to the last index to circulate the front pointer*/
        info->Front=info->Reference;        /*Circulate the front pointer in the array of the queue*/
    }else{
        (info->Front)++;                /*increment the front to point to the next element*/
    }
    (info->Num_OfElements)--;           /*decrement the number of elements inserted*/
}else{
printf("The Queue is empty");           /*The Queue is empty*/
}
}
int Q_Is_Empty(ST_queueInfo *info){
if(0==info->Num_OfElements){
    return 1;
}
return 0;
}
/*
void main(){
    ST_queueInfo Queue;
    int q=0;
    int* q_ptr=&q;
    createQueue(&Queue,6);
    enqueue(&Queue,7);
    enqueue(&Queue,4);
    enqueue(&Queue,5);
    enqueue(&Queue,6);
    enqueue(&Queue,8);
    enqueue(&Queue,9);
    dequeue(&Queue,q_ptr);
    printf("%d",*q_ptr);
    dequeue(&Queue,q_ptr);
    printf("%d",*q_ptr);
    dequeue(&Queue,q_ptr);
    printf("%d",*q_ptr);
    dequeue(&Queue,q_ptr);
    printf("%d",*q_ptr);
    dequeue(&Queue,q_ptr);
    printf("%d",*q_ptr);
    dequeue(&Queue,q_ptr);
    printf("%d",*q_ptr);
    enqueue(&Queue,8);
    enqueue(&Queue,9);
    dequeue(&Queue,q_ptr);
    printf("%d",*q_ptr);
    dequeue(&Queue,q_ptr);
    printf("%d",*q_ptr);
}*/
