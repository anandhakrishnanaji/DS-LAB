#include<stdio.h>
#include<string.h>
int stack[50],qu[50];
int top=-1,front=-1,rear=-1;
int arr[50][50],vis[50],k,ch;
int popq();
void pushq();
void dfs(int n,int t);
void bfs(int n,int t);
int main(void){
    int n;
    for(int i=0;i<50;i++) vis[i]=0;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the relation in matrix form\n");
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
    printf("Enter the verex to start from\n");
    scanf("%d",&k);
    printf("BFS :");
    bfs(k,n);
    printf("\nDFS :");
    dfs(k,n);
}

void pushq(int n){
    if(front==-1){
        front++;
        rear++;
    }
    else rear++;
    qu[rear]=n;
}
int popq(){
    front++;
    return qu[front-1];
}
void bfs(int n,int t){
    pushq(n);
    while(front<=rear){
        int m=qu[front];
        for(int i=0;i<t;i++){
            if(arr[m][i]==1 && vis[i]==0) pushq(i);
        }
        int k=popq();
        if(vis[k]==0) printf("%d ",k);
        vis[k]=1;
    }
    for(int i=0;i<50;i++) vis[i]=0;
}

void dfs(int n,int t){
    stack[++top]=n;
    printf("%d ",stack[top]);
    vis[n]=1;
    while(top!=-1){
        int m=stack[top],f=0;
        for(int i=0;i<t;i++){
            if(vis[i]==0 && arr[m][i]==1){
                stack[++top]=i;
                printf("%d ",stack[top]);
                vis[i]=1;
                f=1;
                break;
            }
        }
        if(f==0) top--;
    }
}
