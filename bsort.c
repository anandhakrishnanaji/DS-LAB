#include<stdio.h>
void bubblesort(int arr[],int n);
int main(void){
  int n,arr[100];
  printf("Enter the size of array: \n");
  scanf("%d",&n);
  printf("Enter the array elements: \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  bubblesort(arr,n);
  for(int i=0;i<n;i++)
    printf("%d\n",arr[i]);
}

void bubblesort(int arr[],int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
      if(arr[j]>arr[j+1]){
	int temp=arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=temp;
      }
    }
  }
}
