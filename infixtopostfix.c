#include<stdio.h>
#include<stdbool.h>
#include <string.h>
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
	if(top==-1){
		return true;
	}
	return false;
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
bool isOperand(char c){
	return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}
void convert(char infix[]){
	int start=0;
	for(int i=0;infix[i]!='\0';i++){
		if(isOperand(infix[i])){
			postfix[start++]=infix[i];
		}
		else if (infix[i]=='('){
			push(infix[i]);
		}
		else if(infix[i]==')'){
			int x=pop();
			while(x!=')'){
				postfix[start++]=x;
				x=pop();
			}
		}
		else{
			if(precedence(infix[i])>precedence(stack[top])){
				push(infix[i]);
			}
			else{
				while(precedence(stack[top])>=precedence(infix[i])){
					postfix[start++]=pop();
				}
				push(infix[i]);
			}
		}
		
	}
	while(!isEmpty()){
		postfix[start++]=pop();
	}
	postfix[start]='\0';
	printf("\nPosfix :\n");
	for(int i=0;postfix[i]!='\0';i++){
		printf("%c",postfix[i]);
	}
}
void main(){
	printf("Enter infix expression :");
	char infix[max];
	scanf("%s",&infix);
	convert(infix);
}