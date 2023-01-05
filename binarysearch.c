#include<stdio.h>
int binarysearch(int a[], int n, int element){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]==element){
            return mid;
        }
        else if(a[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
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
    int index =binarysearch(a,n,element);

    if(index==-1){
        printf("Element not found");
    }
    else{
        printf("Element found at %d ",index);
    }
}