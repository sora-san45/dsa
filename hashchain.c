#include<stdio.h>
#include<stdlib.h>
#define size 10
struct Node{
    int data;
    struct Node * next;
};

struct Node * table[size];
struct Node * create(int d){
    struct Node * n=(struct Node *)malloc(sizeof(struct Node));
    n->data=d;
    n->next=NULL;
}
void add(int a){
    int pos=a%size;
    struct Node * n=create(a);
    if(table[pos]==NULL){
        table[pos]=n;
    }
    else{
        struct Node * temp=table[pos];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
}
void print(){
    for(int i=0;i<size;i++){
        struct Node * j=table[i];
        while(j!=NULL){
            printf("%d ->",j->data);
            j=j->next;
        }
        printf("NULL\n");
    }
}
void main(){
    //initialize all locations with NULL
    for(int i=0;i<size;i++){
        table[i]=NULL;
    }
    int i,num,val;
    printf("Enter the number of elements\n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
    printf("Enter Elements\n");
    scanf("%d",&val);
    add(val);
    }
    printf("\n The hash table is\n");
    print();

}