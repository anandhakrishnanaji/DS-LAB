#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node* link;
}node;
node* top=NULL;
void push(int n);
int pop();
void display();
int main(void){
  int ty;
  while(1){
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    scanf("%d",&ty);
    if(ty==1){
      int num;
      printf("Enter the element: ");
      scanf("%d",&num);
      push(num);
    }
    else if(ty==2){
      int t=pop();
      if(t=='a') printf("Stack Underflow\n");
      else printf("%d\n",t);
    }
    else if(ty==3) display();
    else if(ty==4) break;
  }
}
void push(int n){
  node* newnode=(node *)malloc(sizeof(node*));
  newnode->data=n;
  newnode->link=NULL;
  if(top==NULL) top=newnode;
  else {
    newnode->link=top;
    top=newnode;
  }
}
int pop(){
  node* temp;
  int k='a';
  if(top==NULL) return k;
  else {
    temp=top->link;;
    k=top->data;
    free(top);
    top=temp;
    return k;
  }
}

void display(){
  node* temp=top;
  if(temp==NULL) printf("Empty Stack\n");
  else while(temp!=NULL){
      printf("%d\n",temp->data);
      temp=temp->link;
    }
}
