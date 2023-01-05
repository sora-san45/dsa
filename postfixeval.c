#include<stdio.h>
#include<ctype.h>
int top=-1;
int stack[100];
void push(int item){
    if(top==99){
        printf("full");
    }
    else{
        if(top==-1){
            top=0;
        }
        else{
            top++;
        }
        stack[top]=item;
    }
}
char pop(){
    if(top==-1){
        printf("Empty");
    }
    else{
        return stack[top];
        top--;
    }
}
int postfixeval(char postfix[]){
    for(int i=0;postfix[i]!='\0';i++) {
        char item =postfix[i];
        if(isdigit(item)){
            push(item-'0');
        }
        else if(item=='+' || item=='-' || item=='*' ||item=='/' || item=='^'){
            int a=pop();
            int b=pop();
            switch(item){
                case '+':
                push(a+b);
                break;
                case '-':
                push(b-a);
                break;
                case '*':
                push(a*b);
                break;
                case '/':
                push(b/a);
                break;
                case '^':
                push(a^b);
                break;
            }
        }
        else if(item=='$'){
            return pop(); 
        }
    }
     
}
void main(){
    printf("\nEnter postfix expression\n");
    char postfix[100];
    for(int i=0;i<100;i++){
        scanf("%c",&postfix[i]);
        if(postfix[i]=='$'){
            break;
        }
    }
    int result = postfixeval(postfix);
    printf("%d",result);
}