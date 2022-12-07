#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

struct Node * head=NULL;
struct Node * tail=NULL;

void insertfront(int d){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node *));
    if(head==NULL){
        ptr->data=d;
        ptr->next=NULL;
        head=ptr;
        tail=ptr;
    }
    else{
        ptr->data=d;
        ptr->next=head;
        head=ptr;
    }
}
void insertend(int d){
    struct Node * ptr= (struct Node *)malloc(sizeof(struct Node *));
    if(head==NULL){
        ptr->data=d;
        ptr->next=NULL;
        head=ptr;
        tail=ptr;
    }
    else{
        tail->next=ptr;
        ptr->data=d;
        tail=ptr;
    }
}
void insertbetween(int d1,int d){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node *));
    if(head==NULL){
        printf("Empty list");
    }
    else{
        struct Node * i=head;
        while(i->data!=d1){
            i=i->next;
        }
        struct Node * temp=i->next;
        i->next=ptr;
        ptr->next=temp;
        ptr->data=d;
    }
}
void delete(int d){
    if(head==NULL){
        printf("Empty list");
    }
    else{
        struct Node * i=head;
        while(i->next->data!=d){
            i=i->next;
        }
        struct Node * temp = i->next;
        i->next=temp->next;
        printf("deleted %d",temp->data);
        temp=NULL;
    }
}
void display(){
    if(head==NULL){
        printf("Empty list");
    }
    else{
        struct Node * i=head;
        while(i!=NULL){
            printf("%d ",i->data);
            i=i->next;
        }
    }
}

void main(){
    while(1){
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert after given node\n");
        printf("4. Delete given node\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
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
            int d;
            printf("Enter data for node to be deleted");
            scanf("%d",&d);
            delete(d);
        }
        else if(op==5){
            display();
        }
        else if(op==6){
            break;
        }
        else{
            printf("Invalid option");
        }
    }
}
