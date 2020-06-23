#include<stdio.h>
void selsort(int arr[],int n);
int main(void){
  int n,arr[100];
  printf("Enter the size of array: \n");
  scanf("%d",&n);
  printf("Enter the array elements: \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  selsort(arr,n);
  for(int i=0;i<n;i++)
    printf("%d\n",arr[i]);
}

void selsort(int arr[],int n){
  for(int i=0;i<n;i++){
    int min=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[min])
	min=j;
    }
    int temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
  }
}
	
