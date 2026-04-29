#include<stdio.h>
#include<stdlib.h>

// making queue function
typedef struct queue{
    int size;
    int end;
    int *arr;
}queue;

int isempty(queue*q){
    if(q->end==-1){
        return 1;
    }
    return 0;
}

int isfull(queue*q){
    if(q->end==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(queue*q,int value){
    if(isfull(q)){
        return ;
    }
    else{
        q->end++;
        q->arr[q->end]=value;
    }
}

int front(queue*q){
    if(isempty(q)){
        return 1;
    }
    return q->arr[0];
}

void dequeue(queue*q,int* n ){
   if( isempty(q)){
        return;
    }
     
    else{
       
   for(int i=0;i<*n;i++){
            q->arr[i]=q->arr[i+1];     
        }
       (*n)--;
        q->end--;
    }
}

void print(queue*q,int *n){
    for (int i=0;i<*n;i++){
        printf("%d\n",q->arr[i]);
        
    }
}

int main(){
    queue*q=(queue*)malloc(sizeof(queue));
    q->size=10;
    q->end=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
    int n=4;
    enqueue(q,10);
    enqueue(q,120);
    enqueue(q,130);
    enqueue(q,140);
     enqueue(q,140);
    

    print(q,&n);

    printf("\n");

    dequeue(q,&n);
     dequeue(q,&n);

     print(q,&n);
     
     printf("\n");

   int d= front(q);
   printf("%d",d);

     printf("\n");

     printf("%d",q->end);
    return 0;
}

