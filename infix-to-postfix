#include<stdio.h>
#include<string.h>
#include<math.h>
void post(char inf[],char postfix[]);
int scalc(int v2,int v1,char op);
int calc(char postfix[]);
int pop();
void push(int n);
int arr[20];
int top=-1,var[256];
int main(void){
    char inf[20],postfix[20],c;
    int val;
    var['^']=5;var['*']=3;var['/']=3;var['+']=2;var['-']=2;var['(']=1;
    printf("Enter the variables and their values (PRESS '0' TO STOP)\n");
    scanf("%c ",&c);
    scanf("%d",&val);
    while(c!='0'){
        var[c]=val;
        scanf("\n%c ",&c);
        scanf("%d",&val);
    }
    printf("Enter the Infix expression\n");
    scanf("%s",inf);
    post(inf,postfix);
    printf("Postfix Expression: %s\n",postfix);
    printf("%d\n",calc(postfix));
}
int pop(){
    top--;
    return arr[top+1];
}
void push(int n){
    top++;
    arr[top]=n;
}
void post(char inf[],char postfix[]){
    int i=0,j=0,k=strlen(inf);
    push('(');
    inf[k]=')';
    inf[k+1]='\0';
    while(inf[i]!='\0'){
        if(inf[i]=='(') push('(');
        else if(inf[i]>='a' && inf[i]<='z'){
            postfix[j]=inf[i];
            j++;
        }
        else if(inf[i]=='/' || inf[i]=='-' || inf[i]=='+' || inf[i]=='*' || inf[i]=='^'){
            if(arr[top]=='(') push(inf[i]);
            else{
                if(var[inf[i]]<=var[arr[top]]){
                    while(var[arr[top]]>=var[inf[i]]){
                        postfix[j]=pop();
                        j++;
                    }
                    push(inf[i]);
                }
                else push(inf[i]);
            }
        }
        else if(inf[i]==')'){
            while(arr[top]!='('){
                postfix[j]=pop();
                j++;
            }
            top--;
        }
        if(inf[i+1]=='\0') postfix[j]='\0';
        i++;
    }
}
int calc(char pos[]){
    int i=0;
    while(pos[i]!='\0'){
        if(pos[i]>='a' && pos[i]<='z') push(var[pos[i]]);
        else if(pos[i]=='+' || pos[i]=='-' || pos[i]=='^' || pos[i]=='*' || pos[i]=='/') push(scalc(pop(),pop(),pos[i]));
        i++;
    }
    return pop();
}

int scalc(int v2,int v1,char op){
    switch(op){
        case '+':return (v1+v2);
        case '-':return (v2-v1);
        case '*':return (v1*v2);
        case '/':return (v2/v1);
        case '^':return (pow(v2,v1));
    }
}
