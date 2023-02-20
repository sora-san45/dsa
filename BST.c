#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * root=NULL;
struct Node * create(int d){
    struct Node * n=(struct Node *)malloc(sizeof(struct Node ));
    n->data=d;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct Node * findMin(struct Node * root){
    while( root && root->left!=NULL){
        root=root->left;
    return root;
    }
}
void inorder(struct Node * root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int search(struct Node * root,int num){
    if(root==NULL){
        return 0;
    }
    else if(root->data==num){
        return 1;
    }
    else if(root->data>num){
        search(root->left,num);
    }
    else{
        search(root->right,num);
    }
}
struct Node * insert(struct Node * root, int d){
    if(root==NULL){
        root=create(d);
    }
    else if(d<=root->data){
        root->left=insert(root->left,d);
    }
    else{
        root->right=insert(root->right,d);
    }
    return root;
}
struct Node * delete(struct Node * root,int d){
    if(root==NULL){
        return root;
    }
    else if(d<root->data){
        root->left=delete(root->left,d);
    }
    else if(d>root->data){
        root->right=delete(root->right,d);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        else if (root->left == NULL || root->right==NULL) // only one child
        {
            struct Node *temp = root; // current node
            if (root->left) // if left child
                root = root->left; // change link to that of left child
            else // else if right child
                root = root->right; // change link to that of right child
            free(temp);// and delete the current node
        }
        else
        {
            struct Node *temp = findMin(root->right);  // find minimum of right node (can also be replaced with FindMaximum(root->left))
            root->data = temp->data;                       // and set current node equal to that value
            root->right = delete(root->right, temp->data); // and delete that node
        }
    }
    return root;

}
void main(){
    int ch, data, num;
    do
    {
        printf("\n\n1.Insert\n2.Search\n3.Delete\n4.Display)\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to be inserted\n");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("\nEnter value to be searched\n");
            scanf("%d", &num);
            if (search(root, num))
                printf("\nElement found ");
            else
                printf("\nElement not found ");
            break;
        case 3:
            printf("\nEnter value to be deleted\n");
            scanf("%d", &num);
            root = delete(root,num);

            break;
        case 4:
            inorder(root);
            break;
        }
    } while (ch < 5);
}