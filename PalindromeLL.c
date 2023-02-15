#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * head=NULL;
struct Node * create(int data){
    struct Node * node=(struct Node *)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    return node;
}
void display(struct Node * head){
    struct Node * i = head;
    while(i!=NULL){
        printf("%d ->",i->data);
        i=i->next;
    }
}
bool isPalindrome(struct Node * head){
    struct Node * current = head;
    struct Node * prev=NULL;
    struct Node * after=NULL;
    while(current !=NULL){
        after=current->next;
        current->next=prev;
        prev=current;
        current = after;
    }

    //prev becomes the head of the reversed list
    struct Node * i= head;
    struct Node * j=prev;
    while(i!=NULL){
        if(i->data!=j->data){
            return false;
        }
        i=i->next;
        j=j->next;
    }
    return true;
}
void main(){
    printf("Enter a List \n");
    int n;
    printf("Enter number of elements \n");
    scanf("%d",&n);
    struct Node * last =NULL;
    for(int i=0;i<n;i++){
        int ele;
        printf("Enter data :");
        scanf("%d",&ele);
        struct Node * node =create(ele);
        if(head==NULL){
            head=node;
            last=node;
        }
        else{
            last->next=node;
            last=node;
        }
    }
    display(head);
    if(isPalindrome(head)){
        printf("Palindome");
    }
    else{
        printf("Not Palindrome");
    }
}