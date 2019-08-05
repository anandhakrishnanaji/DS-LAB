#include<stdio.h>
#include<stdlib.h>
void ssort(int arr[1000],int size);
int linear(int arr[1000],int key,int size);
int binary(int arr[1000],int key,int size);
int binrec(int arr[1000],int beg,int end,int key);
int main(void){
  int arr[1000];
  char type;
    int pos=0,size,key;
  printf("Enter the search method:\n1)L for linear search\n2)B for binary search\n3)R for recursive binary search\n");
  scanf("%c",&type);
  if(type!='L' && type!='B' && type!='R'){
    printf("Invalid Input\n");
    exit(0);
  }
  printf("Enter array size: ");
  scanf("%d",&size);
  printf("Enter the key: ");
  scanf("%d",&key);
  printf("Enter the array elements\n");
  for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
  if(type=='L')
    pos=linear(arr,key,size);
  else if(type=='B'){
    ssort(arr,size);
    pos=binary(arr,key,size);
  }
  else{
    ssort(arr,size);
    pos=binrec(arr,0,size,key);
  }
  
  if(pos!=-1)
    printf("position:%d\n",pos);
  else
    printf("Key not found\n");
  

}

void ssort(int arr[1000],int size){
  for(int i=0;i<size-1;i++){
    int min=i;
    for(int j=i+1;j<size;j++){
      if(arr[j]<arr[min])
	min=j;
    }
    int temp=arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
  }
}


int linear(int arr[1000],int key,int size){
  for(int i=0;i<size;i++){
    if(arr[i]==key)
      return i+1;
  }
  return -1;
}

int binary(int arr[1000],int key,int size){
  int beg=0;
  int end=size-1;
  int mid;
  while(beg<=end){
    mid=(beg+end)/2;
    if(beg==end && arr[beg]!=key)
      return -1;
    if(arr[mid]==key)
      return mid+1;
    else if(arr[mid]<key)
      beg=mid+1;
    else if(key<arr[mid])
      end=mid-1;
  }
  return -1;
}

int binrec(int arr[1000],int beg,int end,int key){
  int mid=(beg+end)/2;
  if(beg==end && arr[beg]!=key)
    return -1;
  if(arr[mid]==key)
    return mid+1;
  else if(arr[mid]<key)
    return binrec(arr,mid+1,end,key);
  else if(arr[mid]>key)
    return binrec(arr,beg,mid-1,key);
}

  






  
  
    
    
    
