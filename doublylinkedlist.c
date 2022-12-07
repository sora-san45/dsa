#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

struct Node * head=NULL;
struct Node * tail =NULL;
void insertfront(int d){
    struct Node * newnode = (struct Node *)malloc(sizeof(struct Node *));
    newnode->data=d;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
}
void insertend(int d){
    struct Node * newnode =(struct Node *)malloc(sizeof(struct Node *));
    newnode->data=d;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void insertbetween(int d1,int d){
    if(head==NULL){
        printf("Empty list");
    }
    else{
        struct Node * newnode =(struct Node *)malloc(sizeof(struct Node *));
        newnode->data=d;
        struct Node * i=head;
        while(i->data!=d1){
            i=i->next;
        }
        struct Node * temp = i->next;
        i->next=newnode;
        newnode->prev=i;
        newnode->next=temp;
        temp->prev=newnode;
    }
}
void deletefront(){
    if(head==NULL){
        printf("Empty list");
    }
    else{
        struct Node * temp =head;
        head=temp->next;
        head->prev=NULL;
        free(temp);
    }
}
void deleteback(){
    if(head==NULL){
        printf("Empty list");
    }
    else{
        struct Node * temp=tail;
        tail=temp->prev;
        tail->next=NULL;
        free(temp);

    }
}
void deletebetween(int d){
    if(head==NULL){
        printf("Empty list");
    }
    else{
        struct Node * i=head;
        while(i->data!=d){
            i=i->next;
        }
        struct Node * temp=i->next;
        i->prev->next=temp;
        temp->prev=i->prev;
        free(i);
    }
}
void display(){
    if(head==NULL){
        printf("Empty list");
    }
    else{
        struct  Node * i=head;
        while(i!=NULL){
            printf("%d",i->data);
            i=i->next;
        }
    }
}
void main(){
    while(1){
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert after given node\n");
        printf("4. Delete from front");
        printf("5. Delete from back");
        printf("6. Delete given node\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        int op;
        printf("Enter choice :");
        scanf("%d",&op);
        if(op==1){
            int d;
            printf("Enter data for node");
            scanf("%d",&d);
            insertfront(d);
        }
        else if(op==2){
            int d;
            printf("Enter data for node");
            scanf("%d",&d);
            insertend(d);
        }
        else if(op==3){
            int d,d1;
            printf("Enter data of node after which new node to be inserted");
            scanf("%d",&d1);
            printf("Enter data for node");
            scanf("%d",&d);
            insertbetween(d1,d);
        }
        else if(op==4){
            deletefront();
        }
        else if(op==5){
            deleteback();
        }
        else if(op==6){
            int d;
            printf("Enter data for node to be deleted");
            scanf("%d",&d);
            deletebetween(d);
        }
        else if(op==7){
            display();
        }
        else if(op==8){
            break;
        }
        else{
            printf("Invalid option");
        }
    }
}
