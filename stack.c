#include<stdio.h>
#include<stdlib.h>

#define size 8


int stack[size],top=-1;



void push(int element){
    if (top==size-1){
        printf("Stack Overflow\n");
    }
    else{
        stack[++top]=element;
    }
}

void pop(){
    if (top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Popped element : %d\n",stack[top]);
        top--;
    }
}
void display(){
    if (top==-1){
        printf("Stack Underflow");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d  ",stack[i]);
        }
        printf("\n");
    }
}

void main(){
    while(1){
        int choice;
        printf("1. Push element into stack\n");
        printf("2. Pop element from stack\n");
        printf("3. Display stack elements\n");
        printf("4. Exit\n");
        
        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter element to be pushed :");
            int element;
            scanf("%d",&element);
            push(element);
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(1);

            default:
            printf("Invalid option");
            break;
        }
    }
}