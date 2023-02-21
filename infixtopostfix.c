#include<stdio.h>
#include<stdbool.h>
#include <string.h>
#include<ctype.h>
#define max 100
char stack[max];
char postfix[max];
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
	switch (c){
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

void convert(char infix[]){
	int start=0;
	char x;
	for(int i=0;infix[i]!='\0';i++){
		if(isalnum(infix[i])){
			postfix[start++]=infix[i];
		}
		else if(infix[i]=='('){
			push(infix[i]);
		}
		else if(infix[i]==')'){
			x=pop();
			while(x!='('){
				postfix[start++]=x;
				x=pop();
			}
		}
		else{
			while(precedence(stack[top])>=precedence(infix[i])){
				postfix[start++]=pop();
			}
			push(infix[i]);
		}
	}
	while(!isEmpty()){
		postfix[start++]=pop();
	}
	postfix[start]='\0';
	printf("\nPosfix :\n");
	printf("%s",postfix);
	
}
void main(){
	printf("Enter infix expression :");
	char infix[max];
	scanf("%s",infix);
	convert(infix);
}
