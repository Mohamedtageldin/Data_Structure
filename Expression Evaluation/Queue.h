#ifndef QUEUE_H_
    #define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
typedef struct ST_queueInfo{
    int* Rear,*Front,*Reference;
    int Max_Size;
    int Num_OfElements;
    }ST_queueInfo;
void createQueue(ST_queueInfo* info, int maxSize);
void enqueue(ST_queueInfo *info, int data);
void dequeue(ST_queueInfo *info, int* data);
int Q_Is_Empty(ST_queueInfo *info);
#endif // QUEUE_H_
