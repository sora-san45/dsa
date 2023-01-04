#include<stdio.h>
void merge(int a[],int left, int mid, int right){
    
}
void mergesort(int a[],int left,int right){
    while(left<right){
        int mid=left+(right-left)/2;
        mergesort(a,left,mid-1);
        mergesort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
void main(){
    int n;
    printf("Enter number of elements in array");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements into array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}