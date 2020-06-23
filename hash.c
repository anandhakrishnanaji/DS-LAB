#include<stdio.h>
#include<string.h>
#define max 20
int insert(int n);
int search(int n);
int display();
int arr[max],use[max];
int main(void){
    memset(use,0,sizeof(use)*20);
    int ch,t,y;
    while(1){
        printf("1.Insert\n2.Search\n3.Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the element to be inserted\n");
                scanf("%d",&t);
                if(search(t)!=-1) printf("The element already exists\n");
                else y=insert(t);
                if(y==-1) printf("No Space\n");
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
int insert(int n){
    int mod=n%10,flag=0;
    int i=(mod+1)%max;
    if(use[mod]==0) {
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
    int mod=n%10;
    int i=(mod+1)%max;
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
    while(i<max) {
        if(use[i]==1) {
            printf("%d ",arr[i]);
            flag=1;
        }
        i++;
    }
    if(flag==0) return -1;
    else return 1;
}
