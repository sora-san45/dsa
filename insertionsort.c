#include<stdio.h>
void insertionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(a[j]>temp && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
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