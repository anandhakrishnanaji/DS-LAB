#include<stdio.h>
#include<stdlib.h>
#define max 5
int arr[max],front=-1,rear=-1;
void enq(int n);
int dq();
void display();
int main(void){
  int ty;
  while(1){
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&ty);
    if(ty==1){
      int num;
      printf("Enter the element: ");
      scanf("%d",&num);
      enq(num);
    }
    else if(ty==2) dq();
    
    else if(ty==3) display();
    else if(ty==4) break;
  }
}
void enq(int n){
    if(front==-1 && rear==-1){
        front=0;rear=0;
        arr[rear]=n;
    }
    else {
        rear++;
        if(rear>=max) {
            printf("Queue Full\n");
            rear--;
        }
        else arr[rear]=n;
}
}
int dq(){
    if(front==-1 || rear==-1 || front>rear) printf("Queue Empty\n");
    else {
        printf("%d\n",arr[front]);
        front++;
}
}
void display(){
    if(front==-1 || rear==-1 || front>rear) printf("Queue Empty");
    else for(int i=front;i<=rear;i++) printf("%d ",arr[i]);
    printf("\n");
}
