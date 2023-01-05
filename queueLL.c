#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * front=NULL;
struct Node * rear=NULL;
void enqueue(int d){
    struct Node * newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=d;
    if(front==NULL){
        front=rear=newnode;
    }else{
        rear->next=newnode;
        newnode->next=NULL;
        rear=newnode;
    }
}
void dequeue(){
    if(front==NULL){
        printf("Empty");
    }
    else{
        printf("Deleted %d",front->data);
        struct Node * temp;
        temp=front->next;
        free(temp);
    }
}
void display(){
    if(front ==NULL){
        printf("Empty");
    }
    else{
        struct Node * i=front;
        while(i!=NULL){
            printf(" % d ",i->data);
            i=i->next;
        }
    }
    
}
void main(){
    while(1){
        int choice;
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        
        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter element :");
            int element;
            scanf("%d",&element);
            enqueue(element);
            break;

            case 2:
            dequeue();
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