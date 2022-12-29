#include<stdio.h>
#define size 6

int cqueue[size],front=-1,rear=-1;

void enqueue(int element){
    if((rear+1)%size==front){
        printf("Queue is full\n");
    }
    else if(front==-1){
        front=rear=0;
        cqueue[rear]=element;
    }
    else{
        rear=(rear+1)%size;
        cqueue[rear]=element;
    }
}

void dequeue(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Deleted element :%d\n",cqueue[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }
}

void display(){
    if(front==-1){
        printf("Queue is empty");
    }
    else{
        for(int i=front;i!=rear;i=(i+1)%size){
            printf("%d  ",cqueue[i]);
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