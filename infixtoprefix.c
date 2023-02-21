#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
char stack[100];
int top=-1;
void push(char c){
    stack[++top]=c;
}
char pop(){
    return stack[top--];
}
bool isEmpty(){
    return top==-1;
}
int precedence(char c){
    switch(c){
        case '^':
        return 3;
        case '*':
        return 2;
        case '/':
        return 2;
        case '+':
        return 1;
        case '-':
        return 1;
        default:
        return -1;
    }
}
void infixtoprefix(char exp[]){
    exp=strrev(exp);
    char exp2[100];
    int start=0;
    for(int i=0;exp[i]!='\0';i++){
        if(isalnum(exp[i])){
            exp2[start++]=exp[i];
        }
        else if(exp[i]==')'){
            push(exp[i]);
        }
        else if(exp[i]=='('){
            char x=pop();
            while(x!=')'){
                exp2[start++]=x;
                x=pop();
            }
        }
        else{
            if(precedence(exp[i])>=precedence(stack[top])){
                push(exp[i]);
            }
            else{
                while(precedence(exp[i])<precedence(stack[top])){
                    exp2[start++]=pop();
                }
                push(exp[i]);
            }
        }
    }
    while(!isEmpty()){
        exp2[start++]=pop();
    }
    exp2[start]='\0';
    printf("%s",strrev(exp2));
}
void main(){
    printf("Enter infix exp\n");
    char infix[100];
    scanf("%s",&infix);
    infixtoprefix(infix);
}