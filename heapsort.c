#include<stdio.h>
void heapsort(int arr[],int n);
void heapify(int arr[],int n,int i);
int main(void){
    int arr[10],n;
    printf("Enter the number of elements to be Inserted\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    heapsort(arr,n-1);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

void heapsort(int arr[],int n){
    for(int i=n/2;i>=0;i--) heapify(arr,n,i);
    for(int i=n;i>=0;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
    }
}

void heapify(int arr[],int n,int i){
    int lar=i,l=(2*i)+1,r=(2*i)+2;
    if(l<n && arr[l]>arr[lar]) lar=l;
    if(r<n && arr[r]>arr[lar]) lar=r;
    if(lar!=i){
        int temp=arr[i];
        arr[i]=arr[lar];
        arr[lar]=temp;
        heapify(arr,n,lar);
    }
}