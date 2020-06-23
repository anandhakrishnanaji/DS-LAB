#include<stdio.h>
void isort(int arr[],int n);
int main(void){
  int n,arr[100];
  printf("Enter the size of array: \n");
  scanf("%d",&n);
  printf("Enter the array elements: \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  isort(arr,n);
  for(int i=0;i<n;i++)
    printf("%d\n",arr[i]);
}

void isort(int arr[], int n){
    int key;  
    for (int i=1;i<n;i++){
        key=arr[i];  
        int j=i-1; 
        while (j >=0){
	  if(arr[j]>key){
            arr[j+1]=arr[j];  
            j--;
	  }
        }
        arr[j+1]=key;  
    }
}
  
