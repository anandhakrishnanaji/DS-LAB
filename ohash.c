#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct node{
  int data;
  struct node *link;
}node;
void insert(int n);
int search(int n);
int display();
node* arr[max];
int main(void){
    for(int j=0;j<max;j++) arr[max]=NULL;
    int ch,t;
    while(1){
        printf("1.Insert\n2.Search\n3.Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the element to be inserted\n");
                scanf("%d",&t);
                if(search(t)!=-1) printf("The element already exists\n");
                else insert(t);
                break;
            }
            case 2:{
                printf("Enter the element to be searched\n");
                scanf("%d",&t);
                int k=search(t);
                if(k!=-1) printf("The element is found at index %d\n",k);
                else printf("The element is not found\n");
                break;
            }
            case 3:{
                int k=display();
                if(k==-1) printf("Array Empty");
                printf("\n");
                break;
            }
        }
    }
}

void insert(int n){
    int mod=n%10;
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=n;
    node* temp=arr[mod];
    if(arr[mod]==NULL){
        arr[mod]=newnode;
        newnode->link=NULL;
    }
    else{
        while(temp->link!=NULL) temp=temp->link;
        temp->link=newnode;
    }
}

int search(int n){
    int mod=n%10;
    node* temp=arr[mod];
    while(temp!=NULL){
        if(temp->data==n) return mod;
        temp=temp->link;
    }
    return -1;
}

int display(){
    int i=0,flag=0;
    node* temp;
    while(i<max){
        temp=arr[i];
        while(temp!=NULL){
            printf("%d ",temp->data);
            flag=1;
            temp=temp->link;
        }
        i++;
    }
    if(flag!=1) return -1;
    else return 1;
}
