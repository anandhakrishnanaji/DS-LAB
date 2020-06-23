#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node* link;
}node;
node* front=NULL;
node* rear=NULL;
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
    else if(ty==2){
      int t=dq();
      if(t=='a') printf("Queue Empty\n");
      else printf("%d\n",t);
    }
    else if(ty==3) display();
    else if(ty==4) break;
  }
}

void enq(int n){
  node* newnode=(node *)malloc(sizeof(node*));
  newnode->data=n;
  newnode->link=NULL;
  if(front==NULL && rear==NULL){
    front=newnode;
    rear=newnode;
  }
  else{
    rear->link=newnode;
    rear=newnode;
  }
}

int dq(){
  node* temp;
  int k;
  if(front==NULL) return 'a';
  else{
    temp=front->link;
    k=front->data;
    free(front);
    front =temp;
    return k;
  }
}
void display(){
  node* temp=front;
  if(temp==NULL) printf("Empty Queue\n");
  else while(temp!=NULL){
      printf("%d\n",temp->data);
      temp=temp->link;
    }
}
