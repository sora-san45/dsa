#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * leftchild;
    struct node * rightchild;
};

struct node *create(){
    int d;
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node): ");
    scanf("%d",&d);
    if(d==-1){
        return NULL;
    }
    newnode->data=d;
    printf("Enter left child of %d: \n",d);
    newnode->leftchild=create();
    printf("Enter right child of %d: \n",d);
    newnode->rightchild=create();
}

void preorder(struct node * root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->leftchild);
    preorder(root->rightchild);
}
void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    preorder(root->leftchild);
    printf("%d ",root->data);
    preorder(root->rightchild);
}
void postorder(struct node * root){
    if(root==NULL){
        return;
    }
    preorder(root->leftchild);
    preorder(root->rightchild);
    printf("%d ",root->data);
}

void main(){
    struct node * root=create();  
    preorder(root);
    printf("\n"); 
    inorder(root);
    printf("\n");
    postorder(root);
}