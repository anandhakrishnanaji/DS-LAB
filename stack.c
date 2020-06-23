#include<stdio.h>
int arr[10],top=-1;
int  push(int x);
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
      int k=push(num);
      if(k==-1)
	printf("Stack Overflow\n");
    }
    else if(ty==2){
      int k=pop();
      if(k!='a') printf("%d\n",k);
    }
    else if(ty==3) display();
    else if(ty==4) break;
  }
}

int push(int x){
  top++;
  if(top<10){
    arr[top]=x;
    return 1;
  }
  else return -1;
	 }

int pop(){
  top--;
  if(top<-1){
    printf("Stack Underflow\n");
    return 'a';
  }
  else return arr[top+1];
}

void display(){
  if(top<=-1)
     printf("Empty Stack\n");
  else
     for(int i=top;i>-1;i--)
	 printf("%d\n",arr[i]);
}
