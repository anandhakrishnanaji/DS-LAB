#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *link;
}node;
node* head=NULL;
void insertion(int dat,int pos);
void deletion(int pos);
void traversal();
int searchlist(int key);
int dat,pos,ch;
int main(void){
  while(1){
    printf("Enter 1 for Insertion\nEnter 2 for Deletion\nEnter 3 for traversal\nEnter 4 for Searching\nEnter 5 to Exit\n");
    scanf("%d",&ch);
    if(ch==1){
      printf("Enter the element and position ");
      scanf("%d%d",&dat,&pos);
      insertion(dat,pos);
    }
    else if(ch==2){
      printf("Enter the position ");
      scanf("%d",&pos);
      deletion(pos);
    }
    else if(ch==3)
      traversal();
    
    else if(ch==4){
      int key;
      printf("Enter the key to be searched ");
      scanf("%d",&key);
      int c=searchlist(key);
      if(c!=-1)
	printf("Position %d",c);
      else
	printf("Key not found");
    }
    else if(ch==5)
      exit(0);
    printf("\n");
  }
}

void insertion(int dat,int pos){
  node *newnode=(node*)malloc(sizeof(node));
  newnode->data=dat;
  node* temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->link;
  }
  if(head==NULL){
    head=newnode;
    newnode->link=NULL;
    return;
  }
  else if(pos<1 || pos>count+1){
    printf("Invalid Position\n");
      return;
  }
  else if(pos==1){
    temp=head;
    head=newnode;
    newnode->link=temp;
    return;
  }
  else if(pos==count+1){
    node* temp=head;
    node* temp1;
    while(temp!=NULL){
      temp1=temp;
      temp=temp->link;
    }
    temp1->link=newnode;
    newnode->link=NULL;
  }
  else{
    int i=0;
    node* temp=head;
    node* temp1;
    while(i<pos-2){
      i++;
      temp=temp->link;
    }
    node* lt=temp->link;
    temp->link=newnode;
    newnode->link=lt;
  }
}

void deletion(int pos){
  if(head==NULL){
    printf("Empty\n");
    return;
  }
  node* temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->link;
  }
  if(pos<1 || pos>count){
    printf("INvalid\n");
    return;
  }
  else if(pos==1){
    node*temp=head;
    head=head->link;
    free(temp);
  }
  else if(pos==count){
    node*temp=head;
    int j=0;
    while(j<pos-2){
      j++;
      temp=temp->link;
    }
    free(temp->link);
    temp->link=NULL;
  }
  else{
    node* temp1;
    node* temp=head;
    int j=0;
    while(j<pos-1){
    j++;
    temp1=temp;
    temp=temp->link;
  }
    node* c=temp->link;
    free(temp);
    temp1->link=c;
  }
}

void traversal(){
  node* temp=head;
  while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->link;

  }
}

int searchlist(int key){
  node* temp=head;
  int i=0;
  while(temp!=NULL){
    i++;
    if(temp->data==key)
      return i;
    temp=temp->link;
  }
  return -1;
}
