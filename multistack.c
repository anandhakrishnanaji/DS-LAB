#include<stdio.h>
int arr[10];
int top1=-1,top2=10;
void push(int num,int x);
int pop(int num);
int isnull(int num);
int main(void){
  int ch,elem,num;
  while(1){
    printf("1)Push\n2)Pop\n3)Traverse\n4)Exit\n");
    scanf("%d",&ch);
    if(ch==1){
      printf("Enter the stack number to be pushed: ");
      scanf("%d",&num);
      if(num!=1 && num!=2){
	printf("Invalid Input\n");
	continue;
      }
      printf("Enter the element to be pushed: ");
      scanf("%d",&elem);
      push(num,elem);
    }
    else if(ch==2){
      printf("Enter the stack number to be popped: ");
      scanf("%d",&num);
      if(num!=1 && num!=2){
	printf("Invalid Input\n");
	continue;
      }
	if(isnull(num)!=-1)
      printf("%d\n",pop(num));
	else 
		printf("Stack underflow\n");
    }
    else if(ch==3){
      int flag=-1;
      printf("Enter the stack number to be displayed: ");
      scanf("%d",&num);
      if(num!=1 && num!=2){
	printf("Invalid Input\n");
	continue;
      }
      if(num==1){
	if(isnull(num)!=-1){
	  for(int t=top1;t>-1;t--)
	    printf("%d\n",arr[t]);
	}
	else printf("empty\n");
      }
	else if(num==2){
	  if(isnull(num)!=-1){
	  for(int t=top2;t<10;t++)
	    printf("%d\n",arr[t]);
	  }
	  else printf("Empty\n");
	}
	  
    }
    else
      break;
  }
}

void push(int num,int elem){
  if(num==1){
    if((top1+1)<top2){
      top1++;
      arr[top1]=elem;
    }
    else printf("Stack Overflow\n");
  }
  else if(num==2){
    if((top2-1)>top1){
      top2--;
      arr[top2]=elem;
    }
    else printf("Stack Overflow\n");
  }
}

int pop(int num){
  if(num==1){
    if(top1>-1){
      top1--;
      return arr[top1+1];
    }
    else printf("Stack Underflow\n");
  }
  else if(num==2){
    if(top2<10){
      top2++;
      return arr[top2-1];
    }
    else printf("Stack Underflow\n");
  }
}

int isnull(int num){
  if(num==1){
    if(top1>-1)
      return 1;
    else return -1;
  }
  else if(num==2){
    if(top2<10)
      return 1;
    else return -1;
  }
}
