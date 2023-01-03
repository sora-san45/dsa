#include<stdio.h>
int partition(int a[],int low, int high){
    int pivot=a[low],start=low,end=high;
    while(start<end){
        while(a[start]<=pivot && start<high){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
    int temp=a[low];
    a[low]=a[end];
    a[end]=temp;
    return end;
}
void quicksort(int a[],int low,int high){
    if(low<high){
        int pos=partition(a,low,high);
        quicksort(a,low,pos-1);
        quicksort(a,pos+1,high);
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
    quicksort(a,0,n-1);
}