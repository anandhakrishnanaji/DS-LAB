#include<stdio.h>
#define max 20 
int insert(int n);
int search(int n);
int display();
int arr[max],use[max];
int main(void){
    for(int i=0;i<max;i++) use[i]=0;
    int ty,k,t;
    while(1){
        printf("1.Insert\n2.Search\n3.Display\n");
        scanf("%d",&ty);
        switch(ty){
            case 1:{
                k=0;
                printf("Enter the element to be INserted\n");
                scanf("%d",&t);
                if(search(t)!=-1) printf("The element already Exists\n");
                else k=insert(t);
                if(k==-1) printf("No space\n");
                break;
            }
            case 2:{
                printf("Enter the element to be searched\n");
                scanf("%d",&t);
                k=search(t);
                if(k==-1) printf("Element not found\n");
                else printf("Element found at index %d\n",k);
                break;
            }
            case 3:{
                k=display();
                if(k==-1) printf("Array empty");
                printf("\n");
                break;
            }
        }
    }
}

int insert(int n){
    int mod=n%10,i=(mod+1)%max;
    if(use[mod]==0){
        arr[mod]=n;
        use[mod]=1;
        return 1;
    }
    else{
        while(i!=mod){
            if(use[i]==0){
                arr[i]=n;
                use[i]=1;
                return 1;
            }
            i=(i+1)%max;
        }
    }
    return -1;
}

int search(int n){
    int mod=n%10,i=(mod+1)%max;
    if(use[mod]==0) return -1;
    if(arr[mod]==n) return mod;
    else{
        while(i!=mod){
            if(arr[i]==n) return i;
            i=(i+1)%max;
        }
    }
    return -1;
}

int display(){
    int i=0,flag=0;
    while(i<max){
        if(use[i]==1){
            printf("%d ",arr[i]);
            flag=1;
        }
        i++;
    }
    if(flag==0) return -1;
    else return 1;
}
