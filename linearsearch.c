#include<stdio.h>
int linearsearch(int a[], int n, int element){
    for(int i=0;i<n;i++){
        if(a[i]==element){
            return i;
        }
    }
    return -1;
}
void main(){
    int n;
    printf("Enter number of elements in array :\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements into array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int element;
    printf("Enter element to be searched in array: \n");
    scanf("%d",&element);
    int index =linearsearch(a,n,element);

    if(index==-1){
        printf("Element not found");
    }
    else{
        printf("Element found at %d ",index);
    }
}