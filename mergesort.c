#include<stdio.h>
void merge(int a[],int left, int mid, int right){
    int i=left;
    int j=mid+1;
    int k=left;
    int b[right+1];
    while(i<=mid && j<=right){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=right){
        b[k]=b[j];
        j++;
        k++;
    }
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
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}