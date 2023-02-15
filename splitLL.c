#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * head=NULL;
struct Node * headE=NULL;
struct Node * headO=NULL;

struct Node * create(int data){
    struct Node * node=(struct Node *)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    return node;
} 
struct Node * split(struct Node * head){
    struct Node * i=head;
    struct Node * lastE=NULL;
    struct Node * lastO=NULL;
    while(i!=NULL){
        if(i->data%2==0){
            struct Node * node=create(i->data);
            if(headE==NULL){
                headE=node;
                lastE=node;
            }
            else{
                lastE->next=node;
                lastE=node;
            }
        }
        else{
            struct Node * node=create(i->data);
            if(headO==NULL){
                headO=node;
                lastO=node;
            }
            else{
                lastO->next=node;
                lastO=node;
            }
        }
        i=i->next;
    }
}
void display(struct Node * head){
    struct Node * i = head;
    while(i!=NULL){
        printf("%d ",i->data);
        i=i->next;
    }
}

void main(){
    printf("Enter a linked list\n");
    printf("Enter number of elements:\n");
    int n;
    scanf("%d",&n);
    struct Node * last =NULL;
    for(int i=0;i<n;i++){
        printf("Enter data :");
        int ele;
        scanf("%d",&ele);
        struct Node * node=create(ele);
        if(head==NULL){
            head=node;
            last=node;
        }
        else{
            last->next=node;
            last=node;
        }
    }
    split(head);
    display(headE);
    printf("\n");
    display(headO);

}