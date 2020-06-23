#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* root=NULL;
void insert(int n);
void delete();
node* search(int key);
void traversal(int n);
void pre(node* root);
void post(node* root);
void ino(node* root);
int main(void){
    while(1){
        int ty;
        printf("1.Insert\n2.Delete\n3.Search\n4.Traversal\n5.Exit\n");
        scanf("%d",&ty);
        if(ty==1){
            int num;
            printf("Enter the Element to be inserted \n");
            scanf("%d",&num);
            if(search(num)==NULL) insert(num);
            else printf("The given Number already exists in tree\n");
        }
        else if(ty==2){
            int num;
            printf("Enter the element to be deleted ");
            scanf("%d",&num);
            if(search(num)==NULL) printf("Element doesnt exist \n");
            else delete(num);
        }
        else if(ty==3){
            int num;
            printf("Enter the number to be searched\n");
            scanf("%d",&num);
            if(search(num)!=NULL) printf("Element found\n");
            else printf("Element Not found\n");
        }
        else if(ty==4){
            int ch;
            printf("1.Preorder\n2.Postorder\n3.Inorder\n");
            scanf("%d",&ch);
            traversal(ch);
        }
        else if(ty==5) break;
}
}
node* search(int key){
    node* cur=root;
    while(cur!=NULL){
        if(key==cur->data) return cur;
        else if(key>cur->data) cur=cur->right;
        else if(key<cur->data) cur=cur->left;
    }
    return NULL;
}

void insert(int n){
    node* cur=root,*prev=NULL;
    node* newnode=malloc(sizeof(node*));
    newnode->data=n;
    newnode->right=NULL;
    newnode->left=NULL;
    if(root==NULL) root=newnode;
    else{
    while(cur!=NULL){
        prev=cur;
        if(n==cur->data) break;
        else if(n>cur->data) cur=cur->right;
        else if(n<cur->data) cur=cur->left;
    }
    if(prev->data<n) prev->right=newnode;
    else prev->left=newnode;
    }
}
void traversal(int n){
    if(n==1) pre(root);
    else if(n==2) post(root);
    else if (n==3) ino(root);
}

void pre(node* root){
    if(root==NULL) return;
    else{
        printf("%d ",root->data);
        pre(root->left);
        pre(root->right);
    }
}
void ino(node* root){
    if(root==NULL) return;
    else{
        ino(root->left);
        printf("%d ",root->data);
        ino(root->right);
    }
}
void post(node* root){
    if(root==NULL) return;
    else{
        post(root->left);
        post(root->right);
        printf("%d ",root->data);
    }
}

void delete(int n){
    node* cur=root,*prev=NULL;
    while(cur->data!=n){
        prev=cur;
        if(n==cur->data) break;
        else if(ke->data>cur->data) cur=cur->right;
        else if(ke->data<cur->data) cur=cur->left;
    }
    if(cur->right==NULL && cur->left==NULL){
        if(prev->right==n) prev->right=NULL;
        else prev->left=NULL;
    }
    else if(cur->right!=NULL && cur->left!=NULL){
        node* c=cur->right;
        while(c->left!=NULL) c=c->left;
        cur->data=c->data;
        delete(c->data);
    }
    else{
        
    }
