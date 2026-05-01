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

void enqueue(queue*q,int value, int *n){
    if(isfull(q)){
        return ;
    }
    else{
        q->end++;
        q->arr[q->end]=value;
        (*n)++;
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
    for (int i=0;i<*n-1;i++){
        printf("%d\n",q->arr[i]);
        
    }
}

int main(){
    queue*q=(queue*)malloc(sizeof(queue));
    q->size=10;
    q->end=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
    int n=0;
    enqueue(q,10,&n);
    enqueue(q,120,&n);
    enqueue(q,130,&n);
    enqueue(q,140,&n);
    enqueue(q,140,&n);
    

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

