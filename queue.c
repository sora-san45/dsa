
#include<stdio.h>
#include<stdlib.h>
#define size 8

int queue[size],front=-1,rear=-1;

void enqueue(int element){
    if(rear==size-1){
        printf("Queue is full\n");
    }
    else{
        if(rear==-1){
            front=0;
        }
        queue[++rear]=element;
    }
}

void dequeue(){
    if(rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Deleted element : %d\n",queue[front]);
        front++;
    }
}

void display(){
    if(rear==-1){
        printf("Queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d  ",queue[i]);
        }
        printf("\n");
    }
}

void main(){
    while(1){
        int choice;
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        
        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter element to be added :");
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