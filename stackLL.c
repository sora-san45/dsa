#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * top=NULL;
void push(int d){
    struct Node * newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=d;
    if(top==NULL){
        top=newnode;
    }else{
        newnode->next=top;
        top=newnode;
    }
}
void pop(){
    if(top==NULL){
        printf("Empty");
    }
    else{
        printf("Deleted %d",top->data);
        top=top->next;
    }
}
void display(){
    struct Node * i=top;
    if(front==NULL){
        printf("Empty");
    }
    else{
        while(i!=NULL){
        printf(" % d ",i->data);
        i=i->next;
    }
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
